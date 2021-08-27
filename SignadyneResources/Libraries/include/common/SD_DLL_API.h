#ifndef _SD_DLL_API_H_
#define _SD_DLL_API_H_

#ifdef _SD_DLL_EXPORTING_
    #ifdef __linux__
        #define SD_DLL_API
        #define SD_DLL_API_C        extern "C"
        #define __cdecl
    #else
        #define SD_DLL_API          __declspec(dllexport)
        #define SD_DLL_API_C        extern "C" __declspec(dllexport)
    #endif
 #else
    #ifdef __linux__
        #define SD_DLL_API
    #else
        #define SD_DLL_API          __declspec(dllimport)
        #define SD_DLL_API_C        extern "C" __declspec(dllimport)
    #endif
#endif

extern int lastUnreadError;

#endif //_SD_DLL_API_H_
