#ifndef SD_AIN_C_H
#define SD_AIN_C_H

#include "../common/SD_DLL_API.h"

SD_DLL_API_C int __cdecl SD_AIN_channelInputConfig(int moduleID, int channel, double fullScale, int impedance, int coupling);
SD_DLL_API_C int __cdecl SD_AIN_channelPrescalerConfig(int moduleID, int channel, int prescaler);

//Clock
SD_DLL_API_C int __cdecl SD_AIN_clockIOconfig(int moduleID, int clockConfig);
SD_DLL_API_C double __cdecl SD_AIN_clockGetFrequency(int moduleID);
SD_DLL_API_C double __cdecl SD_AIN_clockGetSyncFrequency(int moduleID);
SD_DLL_API_C double __cdecl SD_AIN_clockSetFrequency(int moduleID, double frequency, int mode = 1);
SD_DLL_API_C int __cdecl SD_AIN_clockResetPhase(int moduleID, int triggerBehavior, int PXItrigger, double skew = 0.0);

//Trigger
SD_DLL_API_C int __cdecl SD_AIN_triggerIOconfig(int moduleID, int direction, int syncMode);
SD_DLL_API_C int __cdecl SD_AIN_triggerIOwrite(int moduleID, int value);
SD_DLL_API_C int __cdecl SD_AIN_triggerIOread(int moduleID);

SD_DLL_API_C int __cdecl SD_AIN_DAQconfig(int moduleID, int nDAQ, int nDAQpointsPerCycle, int nCycles, int triggerDelay, int triggerMode);
SD_DLL_API_C int __cdecl SD_AIN_DAQstart(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_AIN_DAQstop(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_AIN_DAQflush(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_AIN_DAQtrigger(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_AIN_DAQstartMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_AIN_DAQflushMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_AIN_DAQstopMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_AIN_DAQtriggerMultiple(int moduleID, int DAQmask);

SD_DLL_API_C int __cdecl SD_AIN_DAQtriggerConfig(int moduleID, int nDAQ, int digitalTriggerMode, int digitalTriggerSource, int analogTriggerMask);
SD_DLL_API_C int __cdecl SD_AIN_channelTriggerConfig(int moduleID, int nChannel, int analogTriggerMode, double threshold);

SD_DLL_API_C int __cdecl SD_AIN_channelPrescaler(int moduleID, int channel);
SD_DLL_API_C double __cdecl SD_AIN_channelFullScale(int moduleID, int channel);
SD_DLL_API_C double __cdecl SD_AIN_channelMinFullScale(int moduleID, int impedance, int coupling);
SD_DLL_API_C double __cdecl SD_AIN_channelMaxFullScale(int moduleID, int impedance, int coupling);
SD_DLL_API_C int __cdecl SD_AIN_channelImpedance(int moduleID, int channel);
SD_DLL_API_C int __cdecl SD_AIN_channelCoupling(int moduleID, int channel);

SD_DLL_API_C int __cdecl SD_AIN_DAQread(int moduleID, int nDAQ, short *dataBuffer, int nPoints, int timeOut);
SD_DLL_API_C int __cdecl SD_AIN_DAQnPoints(int moduleID, int nDAQ);
//SD_DLL_API_C int __cdecl SD_AIN_DAQfftRead(int moduleID, int nDAQ, double *dataBuffer, int nPoints, bool dB, int windowType, int timeOut);
SD_DLL_API_C int __cdecl SD_AIN_FFT(int moduleID, int channel, short *data, int size, double *result, int resultSize, double *resultPhase, bool dB, int windowType);

#endif //SD_AIN_C_H
