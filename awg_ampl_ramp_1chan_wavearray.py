"""
Single channel, single waveform amplitude ramp from an array.

P. Huft

Connect a 3.3 V trigger to the AWG card and run this script to 
generate a Gaussian pulse once per trigger. 
"""

import os
import sys;
import numpy as np
sys.path.insert(0,'C:/Program Files/Signadyne/Libraries/Python')
import signadyne as sd

"""waveform definition and setup"""

# wait for a trigger?
# start_trig = sd.SD_TriggerModes.AUTOTRIG
start_trig = sd.SD_TriggerModes.EXTTRIG_CYCLE # wait trigger each cycle

# trigger behavior
trig_edge = 4 # falling edge

# onboard clock frequency
f_clk = 1e9

# duration over which to unload the wave from RAM
wfm_tau = 5e-7

# waveform array definition
wfm_pts = 100
sigma = wfm_pts/10 # important to make this small so endpts of the wave are near 0
wfm_arr = np.array([np.exp(-x**2/(2*sigma**2)) for x in np.linspace(-wfm_pts/2,wfm_pts/2,wfm_pts+1)])
wfm_arr[0] = wfm_arr[-1] = 0 # set the endpts to zero

# duration of the waveform to prescaler factor
prescl_from_tau = lambda tau: int(tau*f_clk/(5*wfm_pts)) # manual: 1.2.2.4 Prescaler and Sampling Rate
prescl = prescl_from_tau(wfm_tau)

print("prescl:",prescl)

# card setup
card = sd.SD_AOU()
slot = 12
error = card.openWithSlot("", 0, slot)
if error < 0:
    print("Error =", error)
else:

    for i in range(4):
        card.AWGflush(i)

    # trigger setup. only applies if AWGqueueWaveform has the trigger set to EXTTRIG
    card.AWGtriggerExternalConfig(
        nAWG=0,
        externalSource=0, # manual: Table 16, page 19
        triggerBehavior=trig_edge # manual: Table 17, pages 19
        )

    print("Module opened at slot", slot)
    
    # create a new wave object
    wave=sd.SD_Wave()
    
    # load the wave data from a 1D array of floats
    error = wave.newFromArrayDouble(
        waveformType=sd.SD_WaveformTypes.WAVE_ANALOG, 
        waveformDataA=wfm_arr
        )
    
    # load the wave into the AWG RAM
    error = card.waveformLoad(wave, 0)
    
    # 100 MHz
    card.clockSetFrequency(f_clk)
    
    # modulation - amplitude.
    error = card.modulationAmplitudeConfig(
        nChannel=0,
        modulationType=1, # 0: off, 1: amplitude, 2: offset
        deviationGain=1
        )
        
    print(error)
    
    # configure the channel defaults
    card.channelAmplitude(
        nChannel=0,
        amplitude=0 # volts
        )  
    card.channelFrequency(
        nChannel=0,
        frequency=1.5e8 # [Hz]
        ) 
    card.channelWaveShape(
        nChannel=0,
        waveShape=sd.SD_Waveshapes.AOU_SINUSOIDAL
        )
    # available waveshapes:
    #AOU_OFF,AOU_SINUSOIDAL,AOU_AWG,AOU_TRIANGULAR,AOU_SQUARE,AOU_DC,AOU_AWG,AOU_PARTNER
            
    # queue waveform from RAM
    card.AWGqueueWaveform(
        nAWG=0,
        waveformNumber=0,
        triggerMode=start_trig, # see Manual 1.2.2.5 Trigger
        startDelay=0,
        cycles=0, # 0: infinite cycles.
        prescaler=prescl
        )
    
    card.clockIOconfig(1)
    
    error = card.AWGstart(0)

    if error < 0:
        print("AWG error:", error)
    else:
        print("AWG0 started")
        
    card.close()
    print("AOU closed")