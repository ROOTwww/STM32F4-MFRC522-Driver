#ifndef MFRC522_H
#define MFRC522_H

#include "main.h"

typedef enum {
    COMMANDREG		= 0x01 << 1,
    COMLENREG		= 0x02 << 1,
    DIVLENREG		= 0x03 << 1,
    COMIRQREG		= 0x04 << 1,
    DIVIRQREG		= 0x05 << 1,
    ERRORREG		= 0x06 << 1,
    STATUS1REG		= 0x07 << 1,
    STATUS2REG		= 0x08 << 1,
    FIFODATAREG		= 0x09 << 1,
    FIFOLEVELREG	= 0x0A << 1,
    WATERLEVELREG	= 0x0B << 1,
    CONTROLREG		= 0x0C << 1,
    BITFRAMINGREG	= 0x0D << 1,
    COLLREG		    = 0x0E << 1,
    MODEREG		    = 0x11 << 1,
    TXMODEREG		= 0x12 << 1,
    RXMODEREG		= 0x13 << 1,
    TXCONTROLREG	= 0x14 << 1,
    TXASKREG		= 0x15 << 1,
    TXSELREG		= 0x16 << 1,
    RXSELREG		= 0x17 << 1,
    RXTHRESHOLDREG	= 0x18 << 1,
    DEMODREG		= 0x19 << 1,
    MFTXREG	        = 0x1C << 1,
    MFRXREG		    = 0x1D << 1,
    SERIALSPEEDREG	= 0x1F << 1,
    CRCRESULTREG	= 0x21 << 1,
    RFCFGREG		= 0x26 << 1,
    GSNREG		    = 0x27 << 1,
    CWGSPREG		= 0x28 << 1,
    MODGSPREG		= 0x29 << 1,
    TMODEREG		= 0x2A << 1,
    TPRESCALERREG	= 0x2B << 1,
    TRELOADREG		= 0x2C << 1,
    TCOUNTERVALREG	= 0x2E << 1,
    TESTSEL1REG		= 0x31 << 1,
    TESTSEL2REG		= 0x32 << 1,
    TESTPINENREG	= 0x33 << 1,
    TESTPINVALUEREG	= 0x34 << 1,
    TESTBUSREG		= 0x35 << 1,
    AUTOTESTREG		= 0x36 << 1,
    VERSIONREG		= 0x37 << 1,
    ANALOGTESTREG	= 0x38 << 1,
    TESTDAC1REG		= 0x39 << 1,
    TESTDAC2REG		= 0x3A << 1,
    TESTADCREG		= 0x3B << 1,
}MFRC522_REG;

typedef enum {
    IDLE                = 0B0000,
    MEM                 = 0B0001,
    GENERATERANDOMID    = 0B0010,
    CALCCRC             = 0B0011,
    TRANSMIT            = 0B0100,
    NOCMDCHANGE         = 0B0111,
    RECEIVE             = 0B1000,
    TRANSCEIVE          = 0B1100,
    MFAUTHENT           = 0B1110,
    SOFTRESET           = 0B1111,
}MFRC522_CMD;

void MFRC522_Init(SPI_HandleTypeDef *hspi);
void MFRC522_SoftReset(void);
uint8_t MFRC522_ReadReg(uint8_t address);
void MFRC522_WriteReg(uint8_t address, uint8_t* data, uint8_t amount);
void MFRC522_WriteCMD(MFRC522_CMD CMD);

void __Init(SPI_HandleTypeDef *hspi);
void __Transmit(uint8_t data);
uint8_t __Receive(void);

static SPI_HandleTypeDef *hspix;

#endif /*MFRC522_H*/
