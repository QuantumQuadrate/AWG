#ifndef SD_MODULE_C_H
#define SD_MODULE_C_H

#include "../common/SD_DLL_API.h"

//Open and Close
SD_DLL_API_C int __cdecl SD_Module_openWithSerialNumber(const char *partNumber, const char *serialNumber);
SD_DLL_API_C int __cdecl SD_Module_openWithSlot(const char *partNumber, int nChassis, int nSlot);
SD_DLL_API_C int __cdecl SD_Module_close(int moduleID);

SD_DLL_API_C int __cdecl SD_Module_count();
SD_DLL_API_C int __cdecl SD_Module_getProductNameBySlot(int chassis, int slot, char *name);
SD_DLL_API_C int __cdecl SD_Module_getProductNameByIndex(int index, char *name);
SD_DLL_API_C int __cdecl SD_Module_getSerialNumberBySlot(int chassis, int slot, char *serial);
SD_DLL_API_C int __cdecl SD_Module_getSerialNumberByIndex(int index, char *name);
SD_DLL_API_C int __cdecl SD_Module_getChassisByIndex(int index);
SD_DLL_API_C int __cdecl SD_Module_getSlotByIndex(int index);

SD_DLL_API_C int __cdecl SD_Module_runSelfTest(int moduleID);
SD_DLL_API_C int __cdecl SD_Module_getStatus(int moduleID);
SD_DLL_API_C char *__cdecl SD_Module_getSerialNumber(int moduleID, char *serialNumber);
SD_DLL_API_C char *__cdecl SD_Module_getProductName(int moduleID, char *productName);
SD_DLL_API_C double __cdecl SD_Module_getFirmwareVersion(int moduleID);
SD_DLL_API_C double __cdecl SD_Module_getHardwareVersion(int moduleID);
SD_DLL_API_C int __cdecl SD_Module_getChassis(int moduleID);
SD_DLL_API_C int __cdecl SD_Module_getSlot(int moduleID);

//FPGA
SD_DLL_API_C int __cdecl SD_Module_FPGAreadPCport(int moduleID, int port, int *buffer, int nDW, int address, int addressMode, int accessMode);
SD_DLL_API_C int __cdecl SD_Module_FPGAwritePCport(int moduleID, int port, int *buffer, int nDW, int address, int addressMode, int accessMode);
SD_DLL_API_C int __cdecl SD_Module_FPGAload(int moduleID, const char *fileName);
SD_DLL_API_C int __cdecl SD_Module_FPGAreset(int moduleID, int mode);

//HVI Variables
SD_DLL_API_C int __cdecl SD_Module_readVariable(int moduleID, int varNumber,int &errorOut = lastUnreadError);
SD_DLL_API_C int __cdecl SD_Module_readVariableWithName(int moduleID, const char *varName,int &errorOut = lastUnreadError);
SD_DLL_API_C int __cdecl SD_Module_writeVariable(int moduleID, int varNumber, int varValue);
SD_DLL_API_C int __cdecl SD_Module_writeVariableWithName(int moduleID, const char *varName, int varValue);

SD_DLL_API_C int __cdecl SD_Module_PXItriggerWrite(int moduleID, int nPXItrigger, int value);
SD_DLL_API_C int __cdecl SD_Module_PXItriggerRead(int moduleID, int nPXItrigger);

#endif
