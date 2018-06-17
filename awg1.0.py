import sys
sys.path.insert(0,r'C:\\Users\\Public\\AWGpy\\waveform')
sys.path.insert(0,r'C:\\Program Files\\Signadyne\\Libraries\\Python')
import waveform
import signadyne
import math

#---------------------Parameters------------------------------------
nslot=2
nchannel=0

signal_type=6
signal_amp=1
signal_freq=1000000
signal_offset=0

trigger_mode=0
trigger_behavior=1

awg_auto_type=1
awg_fileaddr=r"C:\\Users\\Public\\AWGpy\\waveformfiles\\"
awg_filename='Gaussian.csv'
awg_file=awg_fileaddr+awg_filename
#print(awg_file)

awg_auto_freq=20000000
awg_auto_square_duty_ratio=1
awg_auto_gaussian_width=6

mod_amp_type=0
mod_amp_gain=0
mod_angle_type=0
mod_angle_gain=1000000

#------------------Default parameters------------------------------

clockfreq=1000000000
errorlist=[]

#------------------Initialize waveform file if necessary-----------
if (awg_auto_type>0)&(awg_auto_type<4):
    w=waveform.wfgen(awg_file)
    if awg_auto_type==1:
        w.wf_ramp(awg_auto_freq)
    elif awg_auto_tpye==2:
        w.wf_square(awg_auto_freq,awg_auto_square_duty_ratio)
    else:
        w.wf_gaussian(awg_auto_freq,awg_auto_gaussian_width)
elif (awg_auto_type<-1)or(awg_auto_type>3):
    message="Error: awg type undefined"
    print(message)
    errorlist.append(message)


#------------------Main program-----------------------------------
    
#-----
card=signadyne.SD_AOU()
error=card.openWithSlot("",0,nslot)
if error<0:
    message="Error: Unable to open module. Error code: "+str(error)
    print(message)
    errorlist.append(message)
else:
    print("Module opened at slot: "+str(nslot))

#-----
if (awg_auto_type>-1):
    wave=signadyne.SD_Wave()
    wave.newFromFile(awg_file)
    card.waveformLoad(wave,0)
    card.AWGflush(0)
    card.AWGqueueWaveform(0,0,0,0,0,0)

#-----
card.clockSetFrequency(clockfreq)

#-----
card.modulationAmplitudeConfig(0,mod_amp_type,mod_amp_gain)
card.modulationAngleConfig(0,mod_angle_type,mod_angle_gain)

card.channelAmplitude(0,signal_amp)
card.channelOffset(0,signal_offset)
card.channelFrequency(0,signal_freq)
card.channelWaveShape(0,signal_type)


#-----
card.AWGstart(0)
card.close()


