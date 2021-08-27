#ifndef _SD_TDC_C_H_
#define _SD_TDC_C_H_

#include "../common/SD_DLL_API.h"
#include "../common/SD_Module_DEFS.h"

//Threshold and Edge Config
SD_DLL_API_C int __cdecl SD_TDC_thresholdConfig(int moduleID, int nChannel, double threshold);
SD_DLL_API_C int __cdecl SD_TDC_edgeConfig(int moduleID, int nChannel, int edge);


SD_DLL_API_C int __cdecl SD_TDC_timeReset(int moduleID);

//Gates
SD_DLL_API_C int __cdecl SD_TDC_HWgateConfig(int moduleID, int nChannel, int globalGateConfig, int channelGateConfig);
SD_DLL_API_C int __cdecl SD_TDC_SWgate(int moduleID, int nChannel, int gateState);
SD_DLL_API_C int __cdecl SD_TDC_SWgateSync(int moduleID, int channelMask, int gateState);

//Rate Counter
SD_DLL_API_C int __cdecl SD_TDC_rateCounterConfig(int moduleID, int nChannel, int timeWindow);
SD_DLL_API_C int __cdecl SD_TDC_rateCounterRead(int moduleID, int nChannel);

//Histogram
SD_DLL_API_C int __cdecl SD_TDC_histogramConfig(int moduleID, int nHistogram, int startChannel, int stopChannel, int binSize, int nBins, long long timeOffset);
SD_DLL_API_C int __cdecl SD_TDC_histogramStart(int moduleID, int nHistogram);
SD_DLL_API_C int __cdecl SD_TDC_histogramPause(int moduleID, int nHistogram);
SD_DLL_API_C int __cdecl SD_TDC_histogramResume(int moduleID, int nHistogram);
SD_DLL_API_C int __cdecl SD_TDC_histogramFlush(int moduleID, int nHistogram);
SD_DLL_API_C int __cdecl SD_TDC_histogramStop(int moduleID, int nHistogram);
SD_DLL_API_C int __cdecl SD_TDC_histogramStartMultiple(int moduleID, int histogramMask);
SD_DLL_API_C int __cdecl SD_TDC_histogramPauseMultiple(int moduleID, int histogramMask);
SD_DLL_API_C int __cdecl SD_TDC_histogramResumeMultiple(int moduleID, int histogramMask);
SD_DLL_API_C int __cdecl SD_TDC_histogramFlushMultiple(int moduleID, int histogramMask);
SD_DLL_API_C int __cdecl SD_TDC_histogramStopMultiple(int moduleID, int histogramMask);
SD_DLL_API_C int __cdecl SD_TDC_histogramRead(int moduleID, int nHistogram, int startBin, int nBins, int *histogramData);

//Timestamps data acquisition
SD_DLL_API_C int __cdecl SD_TDC_DAQconfig(int moduleID, int nDAQ, int DAQpointsPerCycles, int cycles, int prescaler, int triggerMode);
SD_DLL_API_C int __cdecl SD_TDC_DAQstart(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQpause(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQresume(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQflush(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQstop(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQtrigger(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQstartMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_TDC_DAQpauseMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_TDC_DAQresumeMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_TDC_DAQflushMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_TDC_DAQstopMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_TDC_DAQtriggerMultiple(int moduleID, int DAQmask);

SD_DLL_API_C int __cdecl SD_TDC_DAQcounterRead(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQbufferPoolRelease(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_TDC_DAQread(int moduleID, int nDAQ, unsigned long long *dataBuffer, int nPoints, int timeOut);
SD_DLL_API_C int __cdecl SD_TDC_DAQbufferPoolConfig(int moduleID, int nDAQ, unsigned long long *dataBuffer, int nPoints, int timeOut = 0, callbackEventPtr callbackFunction = 0, void *callbackUserObj = 0);
SD_DLL_API_C int __cdecl SD_TDC_DAQbufferAdd(int moduleID, int nDAQ, unsigned long long *dataBuffer, int nPoints);
SD_DLL_API_C unsigned long long* __cdecl SD_TDC_DAQbufferRemove(int moduleID, int nDAQ);
SD_DLL_API_C unsigned long long* __cdecl SD_TDC_DAQbufferGet(int moduleID, int nDAQ, int &readPointsOut, int &errorOut = lastUnreadError);
SD_DLL_API_C int __cdecl SD_TDC_DAQtriggerExternalConfig(int moduleID, int nDAQ, int externalSource, int triggerBehavior);


#endif
