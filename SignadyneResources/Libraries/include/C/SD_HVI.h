#ifndef SD_HVI_C_H
#define SD_HVI_C_H

#include "../common/SD_DLL_API.h"

//Open and Close
SD_DLL_API_C int __cdecl SD_HVI_open(const char *HVIfile);
SD_DLL_API_C int __cdecl SD_HVI_close(int HVIID);

SD_DLL_API_C int __cdecl SD_HVI_compile(int HVIID);
SD_DLL_API_C int __cdecl SD_HVI_compilationErrorMessage(int HVIID, int errorIndex, char *message, int maxSize);
SD_DLL_API_C int __cdecl SD_HVI_load(int HVIID);

SD_DLL_API_C int __cdecl SD_HVI_assignHardwareWithIndexAndSerialNumber(int HVIID, int index, const char *partNumber, const char *serialNumber);
SD_DLL_API_C int __cdecl SD_HVI_assignHardwareWithIndexAndSlot(int HVIID, int index, int nChassis, int nSlot);
SD_DLL_API_C int __cdecl SD_HVI_assignHardwareWithUserNameAndSerialNumber(int HVIID, const char *moduleUserName, const char *partNumber, const char *serialNumber);
SD_DLL_API_C int __cdecl SD_HVI_assignHardwareWithUserNameAndSlot(int HVIID, const char *moduleUserName, int nChassis, int nSlot);

//HVI Control
SD_DLL_API_C int __cdecl SD_HVI_start(int HVIID);
SD_DLL_API_C int __cdecl SD_HVI_pause(int HVIID);
SD_DLL_API_C int __cdecl SD_HVI_resume(int HVIID);
SD_DLL_API_C int __cdecl SD_HVI_stop(int HVIID);
SD_DLL_API_C int __cdecl SD_HVI_reset(int HVIID);

//HVI Modules
SD_DLL_API_C int __cdecl SD_HVI_getNumberOfModules(int HVIID);
SD_DLL_API_C char * __cdecl SD_HVI_getModuleName(int HVIID, int index, char *buffer, int size);
SD_DLL_API_C int __cdecl SD_HVI_getModuleIndex(int HVIID, const char *moduleUserName);
SD_DLL_API_C int __cdecl SD_HVI_getModuleIDwithIndex(int HVIID, int index);
SD_DLL_API_C int __cdecl SD_HVI_getModuleIDwithUserName(int HVIID, const char *moduleUserName);

//HVI Module's Constants
SD_DLL_API_C int __cdecl SD_HVI_readIntegerConstantWithIndex(int HVIID, int moduleIndex, const char *constantName, int &value);
SD_DLL_API_C int __cdecl SD_HVI_readIntegerConstantWithUserName(int HVIID, const char *moduleUserName, const char *constantName, int &value);
SD_DLL_API_C int __cdecl SD_HVI_writeIntegerConstantWithIndex(int HVIID, int moduleIndex, const char *constantName, int value);
SD_DLL_API_C int __cdecl SD_HVI_writeIntegerConstantWithUserName(int HVIID, const char *moduleUserName, const char *constantName, int value);

SD_DLL_API_C int __cdecl SD_HVI_readDoubleConstantWithIndex(int HVIID, int moduleIndex, const char *constantName, double &value, const char * &unit);
SD_DLL_API_C int __cdecl SD_HVI_readDoubleConstantWithUserName(int HVIID, const char *moduleUserName, const char *constantName, double &value, const char * &unit);
SD_DLL_API_C int __cdecl SD_HVI_writeDoubleConstantWithIndex(int HVIID, int moduleIndex, const char *constantName, double value, const char *unit);
SD_DLL_API_C int __cdecl SD_HVI_writeDoubleConstantWithUserName(int HVIID, const char *moduleUserName, const char *constantName, double value, const char *unit);

#endif
