#ifndef SD_ERROR_H
#define SD_ERROR_H

// error codes
#define SD_STATUS_OK                                    0
#define SD_ERROR_NONE									0
#define SD_STATUS_DEMO                                  1

#define SD_ERROR_OFFSET                                 -8000
#define SD_ERROR_NERRORS                                35

//Open and Close Errors
#define SD_ERROR_OPENING_MODULE 						-8000
#define SD_ERROR_OPENING_MODULE_STRING                  "Signadyne Error: Opening module"
#define SD_ERROR_CLOSING_MODULE 						-8001
#define SD_ERROR_CLOSING_MODULE_STRING                  "Signadyne Error: Closing module"
#define SD_ERROR_OPENING_HVI 							-8002
#define SD_ERROR_OPENING_HVI_STRING                     "Signadyne Error: Opening HVI"
#define SD_ERROR_CLOSING_HVI 							-8003
#define SD_ERROR_CLOSING_HVI_STRING                     "Signadyne Error: Closing HVI"
#define SD_ERROR_MODULE_NOT_OPENED                      -8004
#define SD_ERROR_MODULE_NOT_OPENED_STRING               "Signadyne Error: Module not opened"
#define SD_ERROR_MODULE_NOT_OPENED_BY_USER              -8005
#define SD_ERROR_MODULE_NOT_OPENED_BY_USER_STRING       "Signadyne Error: Module not opened by user"
#define SD_ERROR_MODULE_ALREADY_OPENED                  -8006
#define SD_ERROR_MODULE_ALREADY_OPENED_STRING           "Signadyne Error: Module already opened"
#define SD_ERROR_HVI_NOT_OPENED 						-8007
#define SD_ERROR_HVI_NOT_OPENED_STRING                  "Signadyne Error: HVI not opened"

//ID Errors
#define SD_ERROR_INVALID_OBJECTID 						-8008
#define SD_ERROR_INVALID_OBJECTID_STRING				"Signadyne Error: Invalid ObjectID"
#define SD_ERROR_INVALID_MODULEID                       -8009
#define SD_ERROR_INVALID_MODULEID_STRING				"Signadyne Error: Invalid ModuleID"
#define SD_ERROR_INVALID_MODULEUSERNAME                 -8010
#define SD_ERROR_INVALID_MODULEUSERNAME_STRING          "Signadyne Error: Invalid Module User Name"
#define SD_ERROR_INVALID_HVIID                          -8011
#define SD_ERROR_INVALID_HVIID_STRING					"Signadyne Error: Invalid HVI"

#define SD_ERROR_INVALID_OBJECT 						-8012
#define SD_ERROR_INVALID_OBJECT_STRING                  "Signadyne Error: Invalid Object"

#define SD_ERROR_INVALID_NCHANNEL                       -8013
#define SD_ERROR_INVALID_NCHANNEL_STRING                "Signadyne Error: Invalid channel number"

#define SD_ERROR_BUS_DOES_NOT_EXIST                     -8014
#define SD_ERROR_BUS_DOES_NOT_EXIST_STRING              "Signadyne Error: Bus doesn't exist"

#define SD_ERROR_BITMAP_ASSIGNED_DOES_NOT_EXIST            -8015
#define SD_ERROR_BITMAP_ASSIGNED_DOES_NOT_EXIST_STRING     "Signadyne Error: Any input assigned to the bitMap does not exist"

#define SD_ERROR_BUS_INVALID_SIZE                       -8016
#define SD_ERROR_BUS_INVALID_SIZE_STRING                "Signadyne Error: Input size does not fit on this bus"

#define SD_ERROR_BUS_INVALID_DATA                       -8017
#define SD_ERROR_BUS_INVALID_DATA_STRING                "Signadyne Error: Input data does not fit on this bus"

#define SD_ERROR_INVALID_VALUE                          -8018
#define SD_ERROR_INVALID_VALUE_STRING                   "Signadyne Error: Invalid value"

#define SD_ERROR_CREATING_WAVE                          -8019
#define SD_ERROR_CREATING_WAVE_STRING                   "Signadyne Error: Creating Waveform"

#define SD_ERROR_NOT_VALID_PARAMETERS                   -8020
#define SD_ERROR_NOT_VALID_PARAMETERS_STRING            "Signadyne Error: Invalid Parameters"

#define SD_ERROR_AWG                                    -8021
#define SD_ERROR_AWG_STRING                             "Signadyne Error: AWG function failed"

#define SD_ERROR_DAQ_INVALID_FUNCTIONALITY              -8022
#define SD_ERROR_DAQ_INVALID_FUNCTIONALITY_STRING       "Signadyne Error: Invalid DAQ functionality"

#define SD_ERROR_DAQ_POOL_ALREADY_RUNNING               -8023
#define SD_ERROR_DAQ_POOL_ALREADY_RUNNING_STRING        "Signadyne Error: DAQ buffer pool is already running"

#define SD_ERROR_UNKNOWN                                -8024
#define SD_ERROR_UNKNOWN_STRING                         "Signadyne Error: Unknown error"

#define SD_ERROR_INVALID_PARAMETERS                     -8025
#define SD_ERROR_INVALID_PARAMETERS_STRING              "Signadyne Error: Invalid parameter"

#define SD_ERROR_MODULE_NOT_FOUND                       -8026
#define SD_ERROR_MODULE_NOT_FOUND_STRING                "Signadyne Error: Module not found"

#define SD_ERROR_DRIVER_RESOURCE_BUSY                   -8027
#define SD_ERROR_DRIVER_RESOURCE_BUSY_STRING            "Signadyne Error: Driver resource busy"

#define SD_ERROR_DRIVER_RESOURCE_NOT_READY              -8028
#define SD_ERROR_DRIVER_RESOURCE_NOT_READY_STRING       "Signadyne Error: Driver resource not ready"

#define SD_ERROR_DRIVER_ALLOCATE_BUFFER                 -8029
#define SD_ERROR_DRIVER_ALLOCATE_BUFFER_STRING          "Signadyne Error: Cannot allocate buffer in driver"

#define SD_ERROR_ALLOCATE_BUFFER                        -8030
#define SD_ERROR_ALLOCATE_BUFFER_STRING                 "Signadyne Error: Cannot allocate buffer"

#define SD_ERROR_RESOURCE_NOT_READY                     -8031
#define SD_ERROR_RESOURCE_NOT_READY_STRING              "Signadyne Error: Resource not ready"

#define SD_ERROR_HARDWARE                               -8032
#define SD_ERROR_HARDWARE_STRING                        "Signadyne Error: Hardware error"

#define SD_ERROR_INVALID_OPERATION                      -8033
#define SD_ERROR_INVALID_OPERATION_STRING               "Signadyne Error: Invalid Operation"

#define SD_ERROR_NO_COMPILED_CODE                       -8034
#define SD_ERROR_NO_COMPILED_CODE_STRING                "Signadyne Error: No compiled code in the module"

#endif // SD_ERROR_H
