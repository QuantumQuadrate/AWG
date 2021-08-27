#ifndef SD_WAVE_H
#define SD_WAVE_H

#include "SD_Object.h"

class SD_DLL_API SD_Wave : SD_Object
{
public:
    SD_Wave(const char *waveformFile, char *name = 0);
    SD_Wave(int waveformType, int waveformPoints, double *waveformDataA, double *waveformDataB = 0);
    SD_Wave(int waveformType, int waveformPoints, int *waveformDataA, int *waveformDataB = 0);
    SD_Wave(SD_Wave *waveform);

    ~SD_Wave();

    short *getPointVector();
    int getPoints();
    int getStatus();
    int getType();

private:
    int status;
    int points;
    int type;
    short *pointVector;

    int loadFile(const char *waveformFile, char *name = 0);
    int loadWave(int waveformType, int waveformPoints, double *waveformDataA, double *waveformDataB = 0);
    int loadWave(int waveformType, int waveformPoints, int *waveformDataA, int *waveformDataB = 0);
    void freeData();
    void format();
};

#endif // SD_WAVE_H
