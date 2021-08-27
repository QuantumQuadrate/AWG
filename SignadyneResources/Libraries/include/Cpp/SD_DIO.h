#ifndef _SD_DIO_CPP_H_
#define _SD_DIO_CPP_H_

#include "SD_Module.h"
#include "../common/SD_Module_DEFS.h"

class SD_Digital;

/************************ SD_DIO Class *****************************/

class SD_DLL_API SD_DIO : public SD_Module
{
public:
    SD_DIO();
    SD_DIO(SD_Digital* openedModule);
    virtual ~SD_DIO();

    //Open and Close Module
    int open(const char *partNumber, const char *serialNumber);
    int open(const char *partNumber, int nChassis, int nSlot);
    virtual int close();

    //Config
    int IOstandardConfig(int portSector, int logicStandard);
    int IOdirectionConfig(long long lineMask, int direction);

    //Ports
    int portWrite(int nPort, long long portValue);
    int portWriteWithMask(int nPort, long long portValue, long long lineMask);
    long long portRead(int nPort, int &errorOut = lastUnreadError);

    //Buses
    int busConfig(int nBus, int nPort, int StartBit, int EndBit);
    int busWrite(int nBus, int busValue);
    int busRead(int nBus, int &errorOut = lastUnreadError);

    int busSamplingConfig(int nBus, int swichStrobe, int strobeOn, int strobeType, float strobeDelay, int prescaler = 0, int debouncing = 0);

    //Digital Lines
    int lineWrite(int nPort, int nLine, int lineValue);
    int lineRead(int nPort, int nLine);

    //DWG
    int DWGqueueWaveform(int nDWG, int waveformNumber, int triggerMode, int startDelay, int cycles, int prescaler);

    int DWGjumpNextWaveformMultiple(int AWGmask);
    int DWGstartMultiple(int DWGmask);
    int DWGstopMultiple(int DWGmask);
    int DWGresumeMultiple(int DWGmask);
    int DWGpauseMultiple(int DWGmask);
    int DWGtriggerMultiple(int DWGmask);

    int DWGjumpNextWaveform(int nAWG);
    int DWGstart(int nDWG);
    int DWGstop(int nDWG);
    int DWGresume(int nDWG);
    int DWGpause(int nDWG);
    int DWGtrigger(int nDWG);

    int DWGflush(int nDWG);
    int DWG(int nDWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, int *waveformDataA, int *waveformDataB = 0, int paddingMode=0);
    int DWG(int nDWG, const char *waveformFile, int triggerMode, int startDelay, int cycles, int prescaler, int paddingMode = 0);

    int DWGtriggerExternalConfig(int nDWG, int externalSource, int triggerBehavior);

    //DAQ
    int DAQread(int nDAQ, short *dataBuffer, int nPoints, int timeOut);
    int DAQbufferPoolConfig(int nDAQ, short *dataBuffer, int nPoints, int timeOut = 0, callbackEventPtr callbackFunction = 0, void *callbackUserObj = 0);
    int DAQbufferAdd(int nDAQ, short *dataBuffer, int nPoints);
    short *DAQbufferRemove(int nDAQ);
    short *DAQbufferGet(int nDAQ, int &readPointsOut, int &errorOut = lastUnreadError);

    int DWGnWFplaying(int nDWG);
    int DWGisRunning(int nDWG);

private:
    SD_Digital* thisModule;

    int open(SD_Digital *newModule);
};

#endif
