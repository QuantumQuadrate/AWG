#ifndef _SD_TDC_CPP_H_
#define _SD_TDC_CPP_H_

#include "SD_Module.h"
#include "../common/SD_Module_DEFS.h"

class SD_PTM;

/************************ SD_TDC Class *****************************/

class SD_DLL_API SD_TDC : public SD_Module
{
public:
    SD_TDC();
    SD_TDC(SD_PTM* openedModule);
    virtual ~SD_TDC();

    //Open and Close Module
    int open(const char *partNumber, const char *serialNumber);
    int open(const char *partNumber, int nChassis, int nSlot);
    virtual int close();

    int timeReset();

    //Threshold and Edge Config
    int thresholdConfig(int nChannel, double threshold);
    int edgeConfig(int nChannel, int edge);

    //Gates
    int HWgateConfig(int nChannel, int globalGateConfig, int channelGateConfig);
    int SWgate(int nChannel, int gateState);
    int SWgateSync(int channelMask, int gateState);

    //Rate Counter
    int rateCounterConfig(int nChannel, int timeWindow);
    int rateCounterRead(int nChannel);

    //Histogram
    int histogramStartMultiple(int histogramMask);
    int histogramPauseMultiple(int histogramMask);
    int histogramResumeMultiple(int histogramMask);
    int histogramFlushMultiple(int histogramMask);
    int histogramStopMultiple(int histogramMask);

    int histogramConfig(int nHistogram, int startChannel, int stopChannel, int binSize, int nBins, long long timeOffset);
    int histogramStart(int nHistogram);
    int histogramPause(int nHistogram);
    int histogramResume(int nHistogram);
    int histogramFlush(int nHistogram);
    int histogramStop(int nHistogram);
    int histogramRead(int nHistogram, int startBin, int nBins, int *histogramData);

    //Timestamps data acquisition
    int DAQread(int nDAQ, unsigned long long *dataBuffer, int nPoints, int timeOut);
    int DAQbufferPoolConfig(int nDAQ, unsigned long long *dataBuffer, int nPoints, int timeOut, callbackEventPtr callbackFunction, void * callbackUserObj);
    int DAQbufferAdd(int nDAQ, unsigned long long *dataBuffer, int nPoints);
    unsigned long long *DAQbufferRemove(int nDAQ);
    unsigned long long *DAQbufferGet(int nDAQ, int &readPointsOut, int &errorOut = lastUnreadError);

private:
    SD_PTM* thisModule;

    int open(SD_PTM *newModule);
};

#endif
