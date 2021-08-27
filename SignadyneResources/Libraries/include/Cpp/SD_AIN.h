#ifndef _SD_AIN_CPP_H_
#define _SD_AIN_CPP_H_

#include "SD_Module.h"

class SD_Digitizer;

/************************ SD_AIN Class *****************************/

class SD_DLL_API SD_AIN : public SD_Module
{
public:
    SD_AIN();
    SD_AIN(SD_Digitizer* openedModule);
    virtual ~SD_AIN();

    //Open and Close Module
    int open(const char *partNumber, const char *serialNumber);
    int open(const char *partNumber, int nChassis, int nSlot);
    virtual int close();

    int channelInputConfig(int channel, double fullScale, int impedance, int coupling);
    int channelPrescalerConfig(int channel, int prescaler);

    //Clock
    int clockIOconfig(int clockConfig);
    double clockGetFrequency() const;
    double clockGetSyncFrequency() const;
    double clockSetFrequency(double frequency, int mode = 1);
    int clockResetPhase(int triggerBehavior, int PXItrigger, double skew = 0.0);

    //Trigger
    int triggerIOconfig(int direction, int syncMode);
    int triggerIOwrite(int value);
    int triggerIOread() const;

    //DAQ
    int DAQnPoints(int nDAQ) const;
    int DAQread(int nDAQ, short *dataBuffer, int nPoints, int timeOut);

    /*********************************************************
    * DAQconfig
    *   Value       Trigger Mode
        [1:0]=0     Inmediate
        [1:0]=1     HVI
        [1:0]=2     External
        [1:0]=3     Analog
        [3]	Auto    Trigger

    **************************************************************/

    /*********************************************************
    * DAQtriggerConfig
    Bits	Digital TRIGGER MODE
    000     OFF
    001     HIGH
    010     LOW
    011     RISE EDGE
    100     FALL EDGE

    #define TRIGGER_NONE    0
    #define TRIGGER_HIGH    1
    #define TRIGGER_LOW     2
    #define TRIGGER_RISE    3
    #define TRIGGER_FALL    4

    **************************************************************/
    int DAQtriggerConfig(int nDAQ, int digitalTriggerMode, int digitalTriggerSource, int analogTriggerMask);


    /*********************************************************
    * channelTriggerConfig
    Bits	Analog Trigger Mode
    01      THRESHOLD POS
    10      THRESHOLD NEG
    11      THRESHOLD BOTH


    #define AIN_RISING_EDGE     1
    #define AIN_FALLING_EDGE    2
    #define AIN_BOTH_EDGES      3

    **************************************************************/
    int channelTriggerConfig(int nChannel, int AnalogTriggerMode, double threshold);

    int channelPrescaler(int channel) const;
    double channelFullScale(int channel) const;
    double channelMinFullScale(int impedance, int coupling) const;
    double channelMaxFullScale(int impedance, int coupling) const;
    int channelImpedance(int channel) const;
    int channelCoupling(int channel) const;

    int FFT(int channel, short *data, int size, double *result, int resultSize, double *resultPhase = 0, bool dB = false, int windowType = 0);

private:
    SD_Digitizer *thisModule;

    int open(SD_Digitizer *newModule);
};

#endif
