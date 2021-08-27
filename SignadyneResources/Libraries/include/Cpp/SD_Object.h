#ifndef _SD_OBJECT_CPP_H_
#define _SD_OBJECT_CPP_H_

#include "../common/SD_DLL_API.h"

/************************ SD_Object Class *****************************/

class SD_DLL_API SD_Object
{
public:
    SD_Object(int objectType);
    virtual ~SD_Object();

    int getObjectType();
    int isModule();

    static int isModule(int objectType);
    static const char *getErrorMessage(int errorNumber);

protected:
    void setObjectType(int objectType);

private:
    int objectType;
};

#endif
