#ifndef SD_WAVE_C_H
#define SD_WAVE_C_H

#include "../common/SD_DLL_API.h"

//Wave selection and modulation

SD_DLL_API_C int __cdecl SD_Wave_newFromArrayInteger(int waveformType, int waveformPoints, int *waveformDataA, int *waveformDataB = 0);
SD_DLL_API_C int __cdecl SD_Wave_newFromArrayDouble(int waveformType, int waveformPoints, double *waveformDataA, double *waveformDataB = 0);
SD_DLL_API_C int __cdecl SD_Wave_newFromFile(const char *waveformFile);
SD_DLL_API_C int __cdecl SD_Wave_delete(int waveformID);

#endif // SD_WAVE_C_H
