#ifndef _SD_AIO_CPP_H_
#define _SD_AIO_CPP_H_

#include "SD_AIN.h"
#include "SD_AOU.h"

class SD_DLL_API SD_AIO : public SD_AIN , public SD_AOU
{
public:
    SD_AIO();
    virtual ~SD_AIO();

    //Open and Close Module
    int open(const char *partNumber, const char *serialNumber);
    int open(const char *partNumber, int nChassis, int nSlot);

    int close();

    int runSelfTest();
    int getStatus() const;
    char *getSerialNumber(char *serialNumber) const;
    char *getProductName(char *productName) const;
    double getFirmwareVersion() const;
    double getHardwareVersion() const;
    int getChassis() const;
    int getSlot() const;

    //Clock
    int clockIOconfig(int port, int clockConfig);
    double clockGetFrequency(int port) const;
    double clockGetSyncFrequency(int port) const;
    double clockSetFrequency(int port, double frequency, int mode = 1);
    int clockResetPhase(int port, int triggerBehavior, int PXItrigger, double skew = 0.0);

    //Trigger
    int triggerIOconfig(int port, int direction, int syncMode);
    int triggerIOwrite(int port, int value);
    int triggerIOread(int port) const;

    //FPGA
    int FPGAreadPCport(int port, int *buffer, int nDW, int address, SD_AddressingMode::SD_AddressingMode addressMode = SD_AddressingMode::AUTOINCREMENT, SD_AccessMode::SD_AccessMode accessMode = SD_AccessMode::DMA);
    int FPGAwritePCport(int port, int *buffer, int nDW, int address, SD_AddressingMode::SD_AddressingMode addressMode = SD_AddressingMode::AUTOINCREMENT, SD_AccessMode::SD_AccessMode accessMode = SD_AccessMode::DMA);
    int FPGAload(const char *fileName);
    int FPGAreset(SD_ResetMode::SD_ResetMode mode = SD_ResetMode::PULSE);

    //HVI Variables
    int readVariable(int varNumber, int &errorOut = lastUnreadError) const;
    int readVariable(const char *varName, int &errorOut = lastUnreadError) const;
    int writeVariable(int varNumber, int varValue);
    int writeVariable(const char *varName, int varValue);

    //PXItrigger
    int PXItriggerWrite(int nPXItrigger, int value);
    int PXItriggerRead(int nPXItrigger) const;

    //DAQ
    int DAQconfig(int nDAQ, int nDAQpointsPerCycle, int nCycles, int prescaler, int triggerMode);
    int DAQbufferPoolRelease(int nDAQ);
    int DAQcounterRead(int nDAQ) const;
    int DAQtrigger(int nDAQ);
    int DAQstart(int nDAQ);
    int DAQpause(int nDAQ);
    int DAQresume(int nDAQ);
    int DAQflush(int nDAQ);
    int DAQstop(int nDAQ);
    int DAQtriggerMultiple(int DAQmask);
    int DAQstartMultiple(int DAQmask);
    int DAQpauseMultiple(int DAQmask);
    int DAQresumeMultiple(int DAQmask);
    int DAQflushMultiple(int DAQmask);
    int DAQstopMultiple(int DAQmask);

    //Extenal Trigger
    int DAQtriggerExternalConfig(int nDAQ, int externalSource, int triggerBehavior);

    //AWG
    int waveformGetAddress(int waveformNumber);
    int waveformGetMemorySize(int waveformNumber);
    int waveformMemoryGetWriteAddress();
    int waveformMemorySetWriteAddress(int writeAddress);

    int waveformReLoad(int waveformType, int waveformPoints, short *waveformDataRaw, int waveformNumber, int paddingMode = 0);
    int waveformReLoad(SD_Wave *waveformObject, int waveformNumber, int paddingMode = 0);

    int waveformLoad(int waveformType, int waveformPoints, short *waveformDataRaw, int waveformNumber, int paddingMode = 0);
    int waveformLoad(SD_Wave *waveformObject, int waveformNumber, int paddingMode = 0);
    int waveformFlush();
};

#endif
