#ifndef _SD_MODULE_CPP_H_
#define _SD_MODULE_CPP_H_

#include "SD_Object.h"

#include "sd_constants.h"

class SD_Card;
class SD_Wave;

/************************ SD_Object Class *****************************/

class SD_DLL_API SD_Module : public SD_Object
{
public:
    SD_Module(int moduleType);
    SD_Module(SD_Card *moduleOpened, int moduleType, int moduleOpenedByUser);
    virtual ~SD_Module(){}

    static int moduleCount();
    static int getProductName(int chassis, int slot, char *name);
    static int getProductName(int index, char *name);
    static int getSerialNumber(int chassis, int slot, char *serial);
    static int getSerialNumber(int index, char *name);
    static int getChassis(int index);
    static int getSlot(int index);

    virtual int open(const char *partNumber, const char *serialNumber) = 0;
    virtual int open(const char *partNumber, int nChassis, int nSlot) = 0;
    virtual int close();

    int runSelfTest();
    int getStatus() const;
    char *getSerialNumber(char *serialNumber) const;
    char *getProductName(char *productName) const;
    double getFirmwareVersion() const;
    double getHardwareVersion() const;
    int getChassis() const;
    int getSlot() const;

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
    int WGtriggerExternalConfig(int nAWG, int externalSource, int triggerBehavior);
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

protected:
    int isModuleOpenedByUser() const;

    void assignSDcard(SD_Card *moduleOpened, int moduleType, int moduleOpenedByUser);

    int WGqueueWaveform(int WG, int waveformNumber, int triggerMode, int startDelay, int cycles, int prescaler);

    int WGstartMultiple(int WGmask);
    int WGstopMultiple(int WGmask);
    int WGresumeMultiple(int WGmask);
    int WGpauseMultiple(int WGmask);
    int WGtriggerMultiple(int WGmask);

    int WGstart(int nWG);
    int WGstop(int nWG);
    int WGresume(int nWG);
    int WGpause(int nWG);
    int WGtrigger(int nWG);
    int WGjumpNextWaveform(int nWG);
    int WGjumpNextWaveformMultiple(int WGmask);

    int WGflush(int nWG);
    int WG(int nWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, double *waveformDataA, double *waveformDataB = 0, int paddingMode=0);
    int WG(int nWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, int *waveformDataA, int *waveformDataB = 0, int paddingMode=0);
    int WG(int nWG, const char *waveformFile, int triggerMode, int startDelay, int cycles, int prescaler, int paddingMode = 0);

    int WGnWFplaying(int nWG);
    int WGisRunning(int nWG);

private:
    SD_Card *thisModule;
    int moduleOpenedByUser;
};

#endif
