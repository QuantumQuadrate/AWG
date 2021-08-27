import os;
os.chdir('/opt/Signadyne/python'); #path library
import signadyne;

card = signadyne.SD_DIO();
card.openWithSlot('', 1, 6);
card.DAQconfig(0, 100, 1, 0, signadyne.SD_TriggerModes.AUTOTRIG);
card.DAQstart(0);
print(card.DAQread(0, 100, 0));
