#ifndef _SD_HVI_CPP_H_
#define _SD_HVI_CPP_H_

#include "SD_Object.h"

class SD_Module;
class SD_HVI_Core;
template <typename T> class QList;

class SD_DLL_API SD_HVI : public SD_Object
{
public:
    SD_HVI();
    virtual ~SD_HVI();

    //Open and Close
    int open(const char *HVIfile);
    int close();

    int compile();
    int compilationErrorMessage(int errorIndex, char *message, int maxSize);
    int load();

    int assignHardware(int index, const char *partNumber, const char *serialNumber);
    int assignHardware(int index, int nChassis, int nSlot);
    int assignHardware(const char *moduleUserName, const char *partNumber, const char *serialNumber);
    int assignHardware(const char *moduleUserName, int nChassis, int nSlot);

    int readConstant(int moduleIndex, const char *constantName, int &value) const;
    int readConstant(const char *moduleUserName, const char *constantName, int &value) const;
    int writeConstant(int moduleIndex, const char *constantName, int value);
    int writeConstant(const char *moduleUserName, const char *constantName, int value);

    int readConstant(int moduleIndex, const char *constantName, double &value, const char * &unit) const;
    int readConstant(const char *moduleUserName, const char *constantName, double &value, const char * &unit) const;
    int writeConstant(int moduleIndex, const char *constantName, double value, const char *unit);
    int writeConstant(const char *moduleUserName, const char *constantName, double value, const char *unit);

    //HVI Control
    int start();
    int pause();
    int resume();
    int stop();
    int reset();

    //HVI Modules
    int getNumberOfModules() const;
    const char *getModuleName(int index) const;
    char *getModuleName(int index, char *buffer, int size) const;
    int getModuleIndex(const char *moduleUserName) const;
    SD_Module* getModule(int index) const;
    SD_Module* getModule(const char *moduleUserName) const;

protected:
    SD_HVI_Core* thisHVI;
    QList<SD_Module*> *modulesPassedToUser;
};

#endif
