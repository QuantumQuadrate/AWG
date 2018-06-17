import os
import sys;
import math
sys.path.insert(0,'C:/Program Files/Signadyne/Libraries/Python')
import signadyne

def awg_ramp(freq,gain):
        card = signadyne.SD_AOU()
        slot = 2
        error = card.openWithSlot("", 0, slot)
        if error < 0:
                print("Error =", error)
        else:
                print("Module opened at slot", slot)

                waveformFile = "C:/Users/Public/Documents/Signadyne/Examples/Waveforms/awgModulation.csv"
                wave=signadyne.SD_Wave()
                error = wave.newFromFile(waveformFile)
                error = card.waveformLoad(wave,0)

                card.clockSetFrequency(1000000000)
                
                error = card.modulationAmplitudeConfig(0,0,0)
                
                error = card.modulationAngleConfig(0,2,gain*1000000)
                
                card.channelAmplitude(0,1)
                card.channelFrequency(0,freq*1000000)
                card.channelWaveShape(0,1)

                card.AWGflush(0)

                card.AWGqueueWaveform(0,0,0,0,0,1)
                
                error = card.AWGstart(0)

                

                if error < 0:
                        print("AWG from file error:", error)
                else:
                        print("AWG0 started")
                        print("Base frequency = "+str(freq*1000000)+"Hz")
                        print("Maximum frequency gain = "+str(gain*1000000)+"Hz")

                card.close()
	#print("AOU closed")

if __name__=="__main__":
        f=int(sys.argv[1])
        g=int(sys.argv[2])
        awg_ramp(f,g)

