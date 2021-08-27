#ifndef SD_MODULE_DEFS_H
#define SD_MODULE_DEFS_H

/************************** Typedefs ********************************/

/************************************************************************************************
* void callbackEventPtr(SD_Object* SDobject, int eventNumber, void* buffer0, int buffer0Points,
*                       void* buffer1, int buffer1Points, void* userObject, int status);
*/
typedef void (*callbackEventPtr)(void*, int, void*, int, void*, int, void*, int);

#endif
