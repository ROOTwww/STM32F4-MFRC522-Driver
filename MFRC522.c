#include "MFRC522.h"
#include <stdint.h>

//Initialise MFRC at startup with reset
void MFRC522_Init(SPI_HandleTypeDef *hspi) {
    //SPI connected to the module should be enabled in cubemx
  __Init(hspi);
  for (int i = 0; i < 20; i++)__Transmit(IDLE << 5);
  MFRC522_SoftReset();
}

//Resets MFRC internally
void MFRC522_SoftReset(void) {
  MFRC522_WriteReg(COMMANDREG, (uint8_t*)SOFTRESET, 1);
}

//Read the specific register
uint8_t MFRC522_ReadReg(uint8_t address) {
  __Transmit((address & 0x7f) | (TRANSMIT << 5));
  __Transmit(IDLE);
  uint8_t tmp = __Receive();
  return tmp;
}

//Write to the registers as an amount
void MFRC522_WriteReg(uint8_t address, uint8_t *data, uint8_t amount) {
  __Transmit(address & 0x7f);
  for (int i = 0; i < amount; ++i) __Transmit(*(data + i));
}

//Send an command to the MFRC
void MFRC522_WriteCMD(MFRC522_CMD CMD) {
  MFRC522_WriteReg(COMMANDREG, &CMD, 1);
}

//Peripherials(SPI) init function
void __Init(SPI_HandleTypeDef *hspi) {
    //This function uses HAL library for now, I will try to implement
        //register level functions in the future releases.
    //MX_SPI1_Init();
    //HAL_SPI_Init(&hspi1);
    hspix = hspi;
}

//SPI data send function
void __Transmit(uint8_t data) {
	//This function uses HAL library for now, I will try to implement
		//register level functions in the future releases.
	HAL_SPI_Transmit(hspix, &data, sizeof data, 1000);
}

//SPI data receive function
uint8_t __Receive(void) {
	//This function uses HAL library for now, I will try to implement
		//register level functions in the future releases.
	uint8_t *tmp = 0;
	HAL_SPI_Receive(hspix, tmp, 1, 1000);
	return *tmp;
}
