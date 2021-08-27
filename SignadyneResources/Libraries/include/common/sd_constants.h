#ifndef SD_CONSTANTS_DEFINITIONS_H
#define SD_CONSTANTS_DEFINITIONS_H

#define DIR_IN 0
#define DIR_OUT 1

#define STROBE_OFF 0
#define STROBE_ON 1

#define STROBE_LEVEL    2//0b10
#define STROBE_EDGERISE 1
#define STROBE_EDGEFALL 0

#define DEBOUNCING_NONE 0
#define DEBOUNCING_LOW  2//0b10
#define DEBOUNCING_HIGH 3//0b11

#define DIO_INPUT_BUS0   1000
#define DIO_INPUT_BUS1   1001
#define DIO_OUTPUT_BUS0   2000
#define DIO_OUTPUT_BUS1   2001

#define AUTOTRIG        0
#define VIHVITRIG       1
#define SWHVITRIG       1
#define EXTTRIG         2
#define ANALOGTRIG      3
#define ANALOGAUTOTRIG  (3|(1<<3))

#define TRG_INMEDIATE   0
#define TRG_VIHVI       1
#define TRG_SWHVI       1
#define TRG_EXT         2
#define TRG_ANALOG      3
#define TRG_ANALOGAUTO (3|(1<<3))

#define SWHVITRIG_CYCLE 5
#define EXTTRIG_CYCLE   6

#define TRIGGER_NONE    0
#define TRIGGER_HIGH    1
#define TRIGGER_LOW     2
#define TRIGGER_RISE    3
#define TRIGGER_FALL    4

#define TRIGGER_EXTERN  0
#define TRIGGER_PXI     4000

#define PXI_TRIGGERS    8
#define ANALOG_TRIGGER  16

#define AOU_OFF         -1
#define AOU_GND         0
#define AOU_SINUSOIDAL  1
#define AOU_TRIANGULAR  2
#define AOU_SAWTOOTH    3
#define AOU_SQUARE      4
#define AOU_DC          5
#define AOU_AWG         6
#define AOU_PARTNER     8

#define CLK_LOW_JITTER  0
#define CLK_FAST_TUNE   1

#define AOU_MOD_OFF     0
#define AOU_MOD_FM      1
#define AOU_MOD_PHASE   2
#define AOU_MOD_IQ      3
#define AOU_MOD_FM32b   4

#define AOU_MOD_OFF         0
#define AOU_MOD_AM          1
#define AOU_MOD_OFFSET      2
#define AOU_MOD_AMOFFSET    3

#define AOU_TRG_OUT         0
#define AOU_TRG_OUT_SYNC    2
#define AOU_TRG_IN          1
#define AOU_TRG_IN_SYNC     3

#define WAVE_ANALOG       0
#define WAVE_IQ           2
#define WAVE_IQPOLAR      3
#define WAVE_DIGITAL      5
#define WAVE_ANALOG_DUAL  7
#define WAVE_ANALOG_32B   8
#define WAVE_ANALOG_DUAL32B     9

#define TDC_RISING_EDGE     0
#define TDC_FALLING_EDGE    1
#define TDC_BOTH_EDGES      2

#define AIN_RISING_EDGE     1
#define AIN_FALLING_EDGE    2
#define AIN_BOTH_EDGES      3

#define WINDOW_RECTANGULAR 0
#define WINDOW_BARTLETT 1
#define WINDOW_HANNING 2
#define WINDOW_HAMMING 3
#define WINDOW_BLACKMAN 4
#define WINDOW_KAISER 5
#define WINDOW_GAUSS 6

// firmware programming status
#define FW_PROGRAM_IDLE  0
#define FW_PROGRAM_ERASE 1
#define FW_PROGRAM_WRITE 2
#define FW_PROGRAM_VERIFY 3
#define FW_PROGRAM_SUCCESS 4
#define FW_PROGRAM_ABORTED 5

#define RESET_LOW 0
#define RESET_HIGH 1
#define RESET_PULSE 2

//PCport modes
#define ADDRESSING_AUTOINCREMENT 0
#define ADDRESSING_FIXED 1

#define ACCESS_NONDMA 0
#define ACCESS_DMA 1

#endif // SD_CONSTANTS_DEFINITIONS_H
