# This is a library for generating common waveforms.
# Currently we can generate 3 waveforms(ramp,square,gaussian).
import math
class wfgen:
    fp=' '
    def __init__(self,filepath):
        self.fp=str(filepath)
    def freq_to_points(self,freq):
        return int(1000000000/freq)
    def wf_ramp(self,freq):
        datapoints=self.freq_to_points(freq)
        
        increment=2.0/datapoints
        
        f=open(self.fp,'w')
        f.write("waveformName,waveform_ramp\n")
        f.write("waveformPoints,"+str(datapoints)+"\n")
        f.write("waveformType,WAVE_ANALOG_16\n")
        for count in range(int(datapoints/2)):
            f.write(str((count+1)*increment)+",\n")
        for count in range(int(datapoints/2)):
            f.write(str(1-(count+1)*increment)+",\n")
        f.close()
        
        print(self.fp+" is updated with "+str(datapoints)+" datapoints")
    def wf_square(self,freq,duty_ratio):
        datapoints=self.freq_to_points(freq)
        
        high_points=int(float(datapoints)*float(duty_ratio)/float(1+duty_ratio))
        low_points=datapoints-high_points

        f=open(self.fp,'w')
        f.write("waveformName,waveform_square\n")
        f.write("waveformPoints,"+str(datapoints)+"\n")
        f.write("waveformType,WAVE_ANALOG_16\n")
        for count in range(high_points):
            f.write(str(1)+",\n")
        for count in range(low_points):
            f.write(str(0)+",\n")
        f.close()

        print(self.fp+" is updated with "+str(datapoints)+" datapoints")
    def wf_gaussian(self,freq,nsigma):
        datapoints=self.freq_to_points(freq)
        sigma=0.5/float(nsigma)

        f=open(self.fp,'w')
        f.write("waveformName,waveform_Gaussian\n")
        f.write("waveformPoints,"+str(datapoints)+"\n")
        f.write("waveformType,WAVE_ANALOG_16\n")
        for count in range(datapoints):
            f.write(str(math.exp(-((count/datapoints-0.5)/sigma)**2/2))+",\n")
        f.close()

        print(self.fp+" is updated with "+str(datapoints)+" datapoints")
        
