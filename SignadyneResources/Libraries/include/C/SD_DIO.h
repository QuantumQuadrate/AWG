#ifndef SD_DIO_C_H
#define SD_DIO_C_H

#include "../common/SD_DLL_API.h"
#include "../common/SD_Module_DEFS.h"

//Config
SD_DLL_API_C int __cdecl SD_DIO_IOstandardConfig(int moduleID, int portSector, int logicStandard);
SD_DLL_API_C int __cdecl SD_DIO_IOdirectionConfig(int moduleID, long long lineMask, int direction);

//Ports
SD_DLL_API_C int __cdecl SD_DIO_portWrite(int moduleID, int nPort, long long portValue);
SD_DLL_API_C int __cdecl SD_DIO_portWriteWithMask(int moduleID, int nPort, long long portValue, long long lineMask);
SD_DLL_API_C long long __cdecl SD_DIO_portRead(int moduleID, int nPort, int &errorOut = lastUnreadError);

//Buses
SD_DLL_API_C int __cdecl SD_DIO_busConfig(int moduleID, int nBus, int nPort, int StartBit, int EndBit);
SD_DLL_API_C int __cdecl SD_DIO_busWrite(int moduleID, int nBus, int busValue);
SD_DLL_API_C int __cdecl SD_DIO_busRead(int moduleID, int nBus, int &errorOut = lastUnreadError);

SD_DLL_API_C int __cdecl SD_DIO_busSamplingConfig(int moduleID, int nBus, int switchStrobe, int strobeOn, int strobeType, float strobeDelay, int prescaler = 0, int debouncing = 0);

//Digital Lines
SD_DLL_API_C int __cdecl SD_DIO_lineWrite(int moduleID, int nPort, int nLine, int lineValue);
SD_DLL_API_C int __cdecl SD_DIO_lineRead(int moduleID, int nPort, int nLine);

//DWG
SD_DLL_API_C int __cdecl SD_DIO_waveformGetAddress(int moduleID, int waveformNumber);
SD_DLL_API_C int __cdecl SD_DIO_waveformGetMemorySize(int moduleID, int waveformNumber);
SD_DLL_API_C int __cdecl SD_DIO_waveformMemoryGetWriteAddress(int moduleID);
SD_DLL_API_C int __cdecl SD_DIO_waveformMemorySetWriteAddress(int moduleID, int writeAddress);

SD_DLL_API_C int __cdecl SD_DIO_waveformReLoadArrayInt16(int moduleID, int waveformType, int waveformPoints, short *waveformDataRaw, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_DIO_waveformReLoad(int moduleID, int waveformID, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_DIO_waveformLoadArrayInt16(int moduleID, int waveformType, int waveformPoints, short *waveformDataRaw, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_DIO_waveformLoad(int moduleID, int waveformID, int waveformNumber, int paddingMode=0);
SD_DLL_API_C int __cdecl SD_DIO_waveformFlush(int moduleID);
SD_DLL_API_C int __cdecl SD_DIO_DWGqueueWaveform(int moduleID, int nDWG, int waveformNumber, int triggerMode, int startDelay, int cycles, int prescaler);

SD_DLL_API_C int __cdecl SD_DIO_DWGisRunning(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGnWFplaying(int moduleID, int nDWG);

SD_DLL_API_C int __cdecl SD_DIO_DWGjumpNextWaveform(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGstart(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGstop(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGresume(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGpause(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGtrigger(int moduleID, int nDWG);

SD_DLL_API_C int __cdecl SD_DIO_DWGjumpNextWaveformMultiple(int moduleID, int DWGmask);
SD_DLL_API_C int __cdecl SD_DIO_DWGstartMultiple(int moduleID, int DWGmask);
SD_DLL_API_C int __cdecl SD_DIO_DWGstopMultiple(int moduleID, int DWGmask);
SD_DLL_API_C int __cdecl SD_DIO_DWGresumeMultiple(int moduleID, int DWGmask);
SD_DLL_API_C int __cdecl SD_DIO_DWGpauseMultiple(int moduleID, int DWGmask);
SD_DLL_API_C int __cdecl SD_DIO_DWGtriggerMultiple(int moduleID, int DWGmask);

SD_DLL_API_C int __cdecl SD_DIO_DWGflush(int moduleID, int nDWG);
SD_DLL_API_C int __cdecl SD_DIO_DWGfromFile(int moduleID, int nDWG, const char *waveformFile, int triggerMode, int startDelay, int cycles, int prescaler, int paddingMode = 0);
SD_DLL_API_C int __cdecl SD_DIO_DWGfromArray(int moduleID, int nDWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, int* waveformDataA, int* waveformDataB = 0, int paddingMode = 0);
SD_DLL_API_C int __cdecl SD_DIO_DWGtriggerExternalConfig(int moduleID,int nDWG, int externalSource, int triggerBehavior);

//DAQ
SD_DLL_API_C int __cdecl SD_DIO_DAQread(int moduleID, int nDAQ, short *dataBuffer, int nPoints, int timeOut);
SD_DLL_API_C int __cdecl SD_DIO_DAQconfig(int moduleID, int nDAQ, int nDAQpointsPerCycle, int nCycles, int prescaler, int triggerMode);
SD_DLL_API_C int __cdecl SD_DIO_DAQbufferPoolConfig(int moduleID, int nDAQ, short *dataBuffer, int nPoints, int timeOut = 0, callbackEventPtr callbackFunction = 0, void *callbackUserObj = 0);
SD_DLL_API_C int __cdecl SD_DIO_DAQbufferPoolRelease(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQbufferAdd(int moduleID, int nDAQ, short *dataBuffer, int nPoints);
SD_DLL_API_C short* __cdecl SD_DIO_DAQbufferRemove(int moduleID, int nDAQ);
SD_DLL_API_C short* __cdecl SD_DIO_DAQbufferGet(int moduleID, int nDAQ, int &readPointsOut, int &errorOut = lastUnreadError);
SD_DLL_API_C int __cdecl SD_DIO_DAQtriggerExternalConfig(int moduleID, int nDAQ, int externalSource, int triggerBehavior);

SD_DLL_API_C int __cdecl SD_DIO_DAQcounterRead(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQstart(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQpause(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQresume(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQflush(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQstop(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQtrigger(int moduleID, int nDAQ);
SD_DLL_API_C int __cdecl SD_DIO_DAQstartMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_DIO_DAQpauseMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_DIO_DAQresumeMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_DIO_DAQflushMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_DIO_DAQstopMultiple(int moduleID, int DAQmask);
SD_DLL_API_C int __cdecl SD_DIO_DAQtriggerMultiple(int moduleID, int DAQmask);

#endif
