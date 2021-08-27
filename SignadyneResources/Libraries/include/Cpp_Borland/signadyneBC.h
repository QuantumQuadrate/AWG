//---------------------------------------------------------------------------

#ifndef SignadyneBCH
#define SignadyneBCH

#include "..\include\common\sd_constants.h"
#include "..\include\common\SD_Error.h"

class SD_Module
{
	protected:
		int handle;
		int getType(int handle);

	public:
		SD_Module();
		~SD_Module();
		int open(char* partNumber, char* serialNumber);
		int open(char* partNumber, int nChassis, int nSlot);
		virtual int close();
		bool isOpen();
		int getType();
		int getStatus();
		int runSelfTest();

	//HVI Variables
		int readVariable(int varNumber, int &error);
		int readVariable(char* varName, int &error);
		int writeVariable(int varNumber, int varValue);
		int writeVariable(char* varName, int varValue);

	// ******************************
	// PXItrigger
		int PXItriggerWrite(int nPXItrigger, int value);
		int PXItriggerRead(int nPXItrigger);

	// **********************************
	// Waveforms
		int waveformLoad(int waveformType, int waveformPoints, short* dataRaw, int waveformNumber);
		
		int waveformGetAddress(int waveformNumber);
		int waveformGetMemorySize(int waveformNumber);
		int waveformMemoryGetWriteAddress();
		int waveformMemorySetWriteAddress(int writeAddress);		
};


class SD_Error
{
	public:
		const char* getErrorMessage(int errorNumber);
};

class SD_Wave
{
	public:
		SD_Wave(char* waveformFile);
		SD_Wave(int waveformType, int waveformPoints, double* waveformDataA, double* waveformDataB=0);
		SD_Wave(int waveformType, int waveformPoints, int* waveformDataA, int* waveformDataB=0);
		~SD_Wave();
		int getStatus();
		int getType();

	public:
		 int handle;
};

class SD_AOU : public SD_Module
{
	public:
		// **************************************
		// Module Output clock configuration
		int clockSetFrequency(double frequency, int mode);

		// **************************************
		// Module Output synchronization
		int clockResetPhase(int triggerBehavior, int triggerSource, double skew);


		// **************************************
		// Wave selection and modulation
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

		// *****************************************
		// Clock and trigger

		//Clock
		int clockIOconfig(int clockConfig);
		//Trigger
		int triggerIOdirection(int direction);
		int triggerIOconfig(int direction, int syncMode);
		int triggerIOwrite(int value);
		int triggerIOread();

		// *********************************
		// AWG
		int waveformLoad(SD_Wave &waveformObject, int waveformNumber);
		int waveformLoad(int waveformType, int waveformPoints, short* dataRaw, int waveformNumber);

		int waveformFlush();
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
		int AWGflush(int nAWG);
		int AWG(int nAWG, char* waveformFile, int triggerMode, int startDelay, int cycles, int prescaler, int paddingMode=0);
		int AWG(int nAWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, double* waveformDataA, int paddingMode=0);
		int AWG(int nAWG, int triggerMode, int startDelay, int cycles, int prescaler, int waveformType, int waveformPoints, double* waveformDataA, double* waveformDataB=0, int paddingMode=0);

		int AWGtriggerExternalConfig(int nAWG, int externalSource, int triggerBehavior);
		
		int AWGjumpNextWaveform(int nAWG);
		int AWGjumpNextWaveformMultiple(int AWGmask);

		int AWGnWFplaying(int nAWG);
		int AWGisRunning(int nAWG);
};


//---------------------------------------------------------------------------
#endif
