#ifndef SD_CONSTANTS_CPP_H
#define SD_CONSTANTS_CPP_H

namespace SD_ResetMode
{
    enum SD_ResetMode
    {
        LOW = 0,
        HIGH = 1,
        PULSE = 2
    };
}

namespace SD_AddressingMode
{
    enum SD_AddressingMode
    {
        AUTOINCREMENT = 0,
        FIXED = 1
    };
}

namespace SD_AccessMode
{
    enum SD_AccessMode
    {
        NONDMA = 0,
        DMA = 1
    };
}

#endif // SD_CONSTANTS_CPP_H
