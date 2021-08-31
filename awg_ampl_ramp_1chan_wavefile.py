"""
Single channel, single waveform amplitude ramp from a waveform file.

P. Huft

Connect a 3.3 V trigger to the AWG card and run this script to 
generate a Gaussian pulse once per trigger. 
"""

import os
import sys;
import math
sys.path.insert(0,'C:/Program Files/Signadyne/Libraries/Python')
import signadyne as sd

"""waveform definitions"""

# note the lines at the top of the csv file, required by the Signadyne functions
# waveformFile = "C:/Users/Public/Documents/Signadyne/Examples/Waveforms/awgModulationhalf.csv"
waveformFile = "./waveformfiles/Gaussians.csv"

# wait for a trigger?
# start_trig = sd.SD_TriggerModes.AUTOTRIG
start_trig = sd.SD_TriggerModes.EXTTRIG_CYCLE # wait trigger each cycle

# trigger behavior
trig_edge = 4 # falling edge

# onboard clock frequency
f_clk = 1e9

# waveform pts - should match the value given in the waveform file
wfm_pts = 50

# duration over which to unload the wave from RAM
wfm_tau = 2.5e-7

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

    # flush all AWG
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
    
    # load a csv file as the wave data
    error = wave.newFromFile(waveformFile)
    
    # load the wave into the AWG RAM
    error = card.waveformLoad(wave, 0)
    
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
    
    card.AWGflush(0)
        
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