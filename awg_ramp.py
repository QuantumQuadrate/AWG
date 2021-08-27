import os
import sys
import math
sys.path.insert(0,'C:/Program Files/Signadyne/Libraries/Python')
import signadyne

card = signadyne.SD_AOU()
slot = 17
error = card.openWithSlot("", 0, slot)
if error < 0:
	print("Error =", error)
else:
	print("Module opened at slot", slot)

	# waveformFile = "C:/Users/Public/Documents/Signadyne/Examples/Waveforms/Gaussian.csv"
	# wave=signadyne.SD_Wave()
	# error = wave.newFromFile(waveformFile)
	# error = card.waveformLoad(wave,0)
	# card.AWGflush(0)

	# card.AWGqueueWaveform(0,0,0,0,0,0)
	

	# card.clockSetFrequency(1000000000)
        
	# error = card.modulationAmplitudeConfig(0,0,0)
	# print(error)
	# error = card.modulationAngleConfig(0,1,1000000)
	# print(error)
	
	# card.channelAmplitude(0,1)
	# card.channelFrequency(0,2000000)
	# card.channelWaveShape(0,6)


	# error = card.AWGstart(0)

	

	# if error < 0:
		# print("AWG from file error:", error)
	# else:
		# print("AWG0 started")

	card.close()
	print("AOU closed")

