#ifndef SD_AOU_C_H
#define SD_AOU_C_H

#include "../common/SD_DLL_API.h"

SD_DLL_API_C int __cdecl SD_AOU_initialize(int moduleID);

//Wave selection and modulation
SD_DLL_API_C double __cdecl SD_AOU_clockGetFrequency(int moduleID);
SD_DLL_API_C double __cdecl SD_AOU_clockGetSyncFrequency(int moduleID);
SD_DLL_API_C double __cdecl SD_AOU_clockSetFrequency(int moduleID, double frequency, int mode);
SD_DLL_API_C int __cdecl SD_AOU_clockResetPhase(int moduleID, int triggerBehavior, int PXItrigger, double skew);
SD_DLL_API_C int __cdecl SD_AOU_channelWaveShape(int moduleID, int nChannel, int waveShape);
SD_DLL_API_C int __cdecl SD_AOU_channelFrequency(int moduleID, int nChannel, double frequency);
SD_DLL_API_C int __cdecl SD_AOU_channelPhase(int moduleID, int nChannel, double phase);
SD_DLL_API_C int __cdecl SD_AOU_channelPhaseReset(int moduleID, int channel);
SD_DLL_API_C int __cdecl SD_AOU_channelPhaseResetMultiple(int moduleID, int channelMask);
SD_DLL_API_C int __cdecl SD_AOU_channelAmplitude(int moduleID, int nChannel, double amplitude);
SD_DLL_API_C int __cdecl SD_AOU_channelOffset(int moduleID, int nChannel, double offset);

SD_DLL_API_C int __cdecl SD_AOU_modulationAngleConfig(int moduleID, int nChannel, int modulationType, double deviationGain);
SD_DLL_API_C int __cdecl SD_AOU_modulationAmplitudeConfig(int moduleID, int nChannel, int modulationType,double deviationGain);
SD_DLL_API_C int __cdecl SD_AOU_modulationIQconfig(int moduleID, int nChannel, int enable);

//Clock
SD_DLL_API_C int __cdecl SD_AOU_clockIOconfig(int moduleID, int clockConfig);

//Trigger
SD_DLL_API_C int __cdecl SD_AOU_triggerIOconfig(int moduleID, int direction, int syncMode);
SD_DLL_API_C int __cdecl SD_AOU_triggerIOwrite(int moduleID, int value);
SD_DLL_API_C int __cdecl SD_AOU_triggerIOread(int moduleID);

//AWG
SD_DLL_API_C int __cdecl SD_AOU_waveformGetAddress(int moduleID, int waveformNumber);
SD_DLL_API_C int __cdecl SD_AOU_waveformGetMemorySize(int moduleID, int waveformNumber);
SD_DLL_API_C int __cdecl SD_AOU_waveformMemoryGetWriteAddress(int moduleID);
SD_DLL_API_C int __cdecl SD_AOU_waveformMemorySetWriteAddress(int moduleID, int writeAddress);

SD_DLL_API_C int __cdecl SD_AOU_waveformReLoadArrayInt16(int moduleID, int waveformType, int waveformPoints, short *waveformDataRaw, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_AOU_waveformReLoad(int moduleID, int waveformID, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_AOU_waveformLoadArrayInt16(int moduleID, int waveformType, int waveformPoints, short *waveformDataRaw, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_AOU_waveformLoad(int moduleID, int waveformID, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_AOU_waveformFlush(int moduleID);
SD_DLL_API_C int __cdecl SD_AOU_AWGqueueWaveform(int moduleID, int nAWG, int waveformNumber, int triggerMode, int startDelay, int cycles, int prescaler);

SD_DLL_API_C int __cdecl SD_AOU_waveformLoadP2Pstart(int moduleID, int wfType, int points, int waveformNumber);
SD_DLL_API_C int __cdecl SD_AOU_waveformLoadP2Pclose(int moduleID, int nDWwritten);
SD_DLL_API_C unsigned long long __cdecl SD_AOU_waveformLoadP2PgetPhysicalAddress(int moduleID);
SD_DLL_API_C int __cdecl SD_AOU_waveformLoadP2PwriteDataTest(int moduleID, int wfType, int points, short *dataRaw, int paddingMode=0);

SD_DLL_API_C int __cdecl SD_AOU_AWGstart(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGstop(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGresume(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGpause(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGtrigger(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGjumpNextWaveform(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGjumpNextWaveformMultiple(int moduleID, int AWGmask);

SD_DLL_API_C int __cdecl SD_AOU_AWGisRunning(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGnWFplaying(int moduleID, int nAWG);

SD_DLL_API_C int __cdecl SD_AOU_AWGstartMultiple(int moduleID, int AWGmask);
SD_DLL_API_C int __cdecl SD_AOU_AWGstopMultiple(int moduleID, int AWGmask);
SD_DLL_API_C int __cdecl SD_AOU_AWGresumeMultiple(int moduleID, int AWGmask);
SD_DLL_API_C int __cdecl SD_AOU_AWGpauseMultiple(int moduleID, int AWGmask);
SD_DLL_API_C int __cdecl SD_AOU_AWGtriggerMultiple(int moduleID, int AWGmask);

SD_DLL_API_C int __cdecl SD_AOU_AWGflush(int moduleID, int nAWG);
SD_DLL_API_C int __cdecl SD_AOU_AWGfromFile(int moduleID, int nAWG, const char *waveformFile, int triggerMode, int startDelay, int cycles, int prescaler, int paddingMode = 0);
SD_DLL_API_C int __cdecl SD_AOU_AWGfromArray(int moduleID, int nAWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, double* waveformDataA, double* waveformDataB = 0, int paddingMode = 0);
SD_DLL_API_C int __cdecl SD_AOU_AWGtriggerExternalConfig(int moduleID, int nAWG, int externalSource, int triggerBehavior);

SD_DLL_API_C int __cdecl SD_AOU_AWGqueueConfig(int moduleID, int nAWG, int mode);
SD_DLL_API_C int __cdecl SD_AOU_AWGqueueConfigRead(int moduleID, int nAWG);

SD_DLL_API_C int __cdecl SD_AOU_AWGqueueMarkerConfig(int moduleID, int nAWG, int markerMode, int trgPXImask, int trgIOmask, int value, int syncMode, int length, int delay);
SD_DLL_API_C int __cdecl SD_AOU_AWGqueueSyncMode(int moduleID, int nAWG, int syncMode);

#endif
