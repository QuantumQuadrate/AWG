"""
Multiple channel, single waveform per channel, amplitude ramp from an array.

P. Huft

Connect a 3.3 V trigger to the AWG card and run this script to 
generate a Gaussian pulse with a channel dependent delay on each
channel once per trigger. 
"""

import os
import sys;
import numpy as np
from collections import namedtuple
sys.path.insert(0,'C:/Program Files/Signadyne/Libraries/Python')
import signadyne as sd

"""clock and trigger setup"""

# use the same trigger to execute all waveforms in a cycle

# trigger type decided below

# trigger behavior
trig_edge = 4 # falling edge

# onboard clock frequency
f_clk = 1e9

"""waveform array definitions - see single channel scripts for more explanation"""

# waveform type definition
Waveform = namedtuple('Waveform',['mod_type','tau','pts','sigma','arr','prescl','delay','trig_type','SDwave'])
ModTypes = {'amplitude':'modulationAmplitudeConfig', 'frequency':'modulationAngleConfig'}

wfm_mod = 'amplitude'
wfm_tau = 5e-7 # duration
wfm_pts = 100
sigma = wfm_pts/10 # make this small so endpts of the wave are near 0
wfm_arr = np.array([np.exp(-x**2/(2*sigma**2)) for x in np.linspace(-wfm_pts/2,wfm_pts/2,wfm_pts+1)])
wfm_arr[0] = wfm_arr[-1] = 0 # set the endpts to zero

# duration of the waveform to prescaler factor
prescl_from_tau = lambda tau: int(tau*f_clk/(5*wfm_pts)) # manual: 1.2.2.4 Prescaler and Sampling Rate
prescl = prescl_from_tau(wfm_tau)

# when to start after the trigger
delay = 10 # [10 ns]

# mod_type attr is unused in this script; amplitude modulation harcoded.
mod_type = ModTypes['amplitude']
start_trig = sd.SD_TriggerModes.EXTTRIG_CYCLE
wfm0 = Waveform(mod_type,wfm_tau,wfm_pts,sigma,wfm_arr,prescl,delay,start_trig,sd.SD_Wave())
wfm1 = Waveform(mod_type,wfm_tau,wfm_pts,sigma,wfm_arr,prescl,0,start_trig,sd.SD_Wave())
wfm1 = Waveform(mod_type,wfm_tau,wfm_pts,sigma,wfm_arr,prescl,delay,start_trig,sd.SD_Wave())
waveforms = [wfm0, wfm1]

"""channel defaults"""

# for now, I leave the settings for each channel the same, set below
channels = [0,1]

""" card and channel setup """
card = sd.SD_AOU()
slot = 12
error = card.openWithSlot("", 0, slot) # productName, chassis can be left blank/0.
if error < 0:
    print("Error =", error)
else:
    
    print("Module opened at slot", slot)
    
    # clock frequency
    card.clockSetFrequency(f_clk)
    
    # flush old waveforms
    for i in range(4):
        card.AWGflush(i)

    for chan, wfm in zip(channels,waveforms):

        # trigger setup. only applies if AWGqueueWaveform has the trigger set to EXTTRIG
        card.AWGtriggerExternalConfig(
            nAWG=chan,
            externalSource=0, # manual: Table 16, page 19
            triggerBehavior=trig_edge # manual: Table 17, pages 19
            )        
        
        # load the wave data from a 1D array of floats
        error = wfm.SDwave.newFromArrayDouble(
            waveformType=sd.SD_WaveformTypes.WAVE_ANALOG, 
            waveformDataA=wfm.arr
            )
        
        # load the wave into the AWG RAM
        error = card.waveformLoad(wfm.SDwave, chan)
        
        # modulation - amplitude.
        error = card.modulationAmplitudeConfig(
            nChannel=chan,
            modulationType=1, # 0: off, 1: amplitude, 2: offset
            deviationGain=1
            )
            
        print(error)
        
        # configure the channel defaults
        card.channelAmplitude(
            nChannel=chan,
            amplitude=0 # volts
            )  
        card.channelFrequency(
            nChannel=chan,
            frequency=1.5e8 # [Hz]
            ) 
        card.channelWaveShape(
            nChannel=chan,
            waveShape=sd.SD_Waveshapes.AOU_SINUSOIDAL
            )
        # available waveshapes:
        #AOU_OFF,AOU_SINUSOIDAL,AOU_AWG,AOU_TRIANGULAR,AOU_SQUARE,AOU_DC,AOU_AWG,AOU_PARTNER
            
        # queue waveform from RAM
        card.AWGqueueWaveform(
            nAWG=chan,
            waveformNumber=0,
            triggerMode=wfm.trig_type, # see Manual 1.2.2.5 Trigger
            startDelay=wfm.delay,
            cycles=0, # 0: infinite cycles
            prescaler=wfm.prescl
            )
        
    card.clockIOconfig(1)
    
    for chan in channels:
        error = card.AWGstart(chan)
    
    if error < 0:
        print("AWG error:", error)
    else:
        print("AWG0 started")
        
    card.close()
    print("AOU closed")