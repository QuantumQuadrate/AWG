#ifndef _SD_AOU_CPP_H_
#define _SD_AOU_CPP_H_

#include "SD_Module.h"

class SD_Analog;

/************************ SD_AOU Class *****************************/

class SD_DLL_API SD_AOU : public SD_Module
{
public:
    SD_AOU();
    SD_AOU(SD_Analog* openedModule);
    virtual ~SD_AOU();

    //Open and Close Module
    int open(const char *partNumber, const char *serialNumber);
    int open(const char *partNumber, int nChassis, int nSlot);
    virtual int close();

    int initialize();

    //Clock
    int clockIOconfig(int clockConfig);
    double clockGetFrequency() const;
    double clockGetSyncFrequency() const;
    double clockSetFrequency(double frequency, int mode);
    int clockResetPhase(int triggerBehavior, int PXItrigger, double skew);

    //Wave selection and modulation
    int channelWaveShape(int nChannel, int waveShape);
    int channelFrequency(int nChannel, double frequency);
    int channelPhase(int nChannel, double phase);
    int channelPhaseReset(int nChannel);
    int channelPhaseResetMultiple(int channelMask);
    int channelAmplitude(int nChannel, double amplitude);
    int channelOffset(int nChannel, double offset);

    int modulationAngleConfig(int nChannel, int modulationType, double deviationGain);
    int modulationAmplitudeConfig(int nChannel, int modulationType, double deviationGain);
    int modulationIQconfig(int nChannel, int enable);

    //Trigger
    int triggerIOconfig(int direction, int syncMode);
    int triggerIOwrite(int value);
    int triggerIOread() const;

    //AWG
    int AWGqueueWaveform(int nAWG, int waveformNumber, int triggerMode, int startDelay, int cycles, int prescaler);

    int AWGstartMultiple(int AWGmask);
    int AWGstopMultiple(int AWGmask);
    int AWGresumeMultiple(int AWGmask);
    int AWGpauseMultiple(int AWGmask);
    int AWGtriggerMultiple(int AWGmask);

    int AWGstart(int nAWG);
    int AWGstop(int nAWG);
    int AWGresume(int nAWG);
    int AWGpause(int nAWG);
    int AWGtrigger(int nAWG);
    int AWGjumpNextWaveform(int nAWG);
    int AWGjumpNextWaveformMultiple(int AWGmask);

    int AWGflush(int nAWG);
    int AWG(int nAWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, double *waveformDataA, double *waveformDataB = 0, int paddingMode = 0);
    int AWG(int nAWG, const char *waveformFile, int triggerMode, int startDelay, int cycles, int prescaler, int paddingMode = 0);

    int AWGtriggerExternalConfig(int nAWG, int externalSource, int triggerBehavior);
    int AWGqueueConfig(int nAWG, int mode);
    int AWGqueueConfigRead(int nAWG) const;

    int AWGqueueMarkerConfig(int nAWG, int markerMode, int trgPXImask, int trgIOmask, int value, int syncMode, int length, int delay);
    int AWGqueueSyncMode(int nAWG, int syncMode);

    int AWGnWFplaying(int nAWG);
    int AWGisRunning(int nAWG);

    int waveformLoadP2Pstart(int wfType, int points, int waveformNumber);
    int waveformLoadP2Pclose(int nDWwritten);
    unsigned long long waveformLoadP2PgetPhysicalAddress();
    int waveformLoadP2PwriteDataTest(int wfType, int points, short *dataRaw, int paddingMode = 0);

private:
    SD_Analog *thisModule;

    int open(SD_Analog *newModule);
};

#endif
