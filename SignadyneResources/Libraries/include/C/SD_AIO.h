#ifndef SD_AIO_C_H
#define SD_AIO_C_H

#include "../common/SD_DLL_API.h"

//Clock
SD_DLL_API_C int __cdecl SD_AIO_clockIOconfig(int moduleID, int port, int clockConfig);
SD_DLL_API_C double __cdecl SD_AIO_clockGetFrequency(int moduleID, int port);
SD_DLL_API_C double __cdecl SD_AIO_clockGetSyncFrequency(int moduleID, int port);
SD_DLL_API_C double __cdecl SD_AIO_clockSetFrequency(int moduleID, int port, double frequency, int mode = 1);
SD_DLL_API_C int __cdecl SD_AIO_clockResetPhase(int moduleID, int port, int triggerBehavior, int PXItrigger, double skew = 0.0);

//Trigger
SD_DLL_API_C int __cdecl SD_AIO_triggerIOconfig(int moduleID, int port, int direction, int syncMode);
SD_DLL_API_C int __cdecl SD_AIO_triggerIOwrite(int moduleID, int port, int value);
SD_DLL_API_C int __cdecl SD_AIO_triggerIOread(int moduleID, int port);

#endif // SD_AIO_C_H
