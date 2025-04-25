/*
 * i2c.c
 *
 *  Created on: 23 abr. 2025
 *      Author: DANNY
 */

#include "i2c.h"

I2C_HandleTypeDef hi2c1;

/*
 * @brief I2C GPIO Configuration PA9(D1)->SCL and PA10(D0)->SDA
 */
void i2c_I2C1_GPIO_Config(void){
	//I2C1 AF GPIO pins configuration
	GPIO_Handle_t i2cPins;
	i2cPins.pGPIOx=GPIOA;
	i2cPins.pinMode=PIN_MODE_ALTFN;
	i2cPins.pinOutputType=PIN_OP_TYPE_OD;
	i2cPins.pinPUPDControl=PIN_NO_PUPD;
	i2cPins.pinSpeed=PIN_SPEED_HIGH;
	i2cPins.pinAltFunMode=AF4;
	i2cPins.pinNumber=PIN_NO_9;//SCL
	gpio_Init(&i2cPins);
	i2cPins.pinNumber=PIN_NO_10;//SDA
	gpio_Init(&i2cPins);
}

/*
 * @brief I2C Peripheral Config
 */
void i2c_I2C1_Config(void){
	//Enable I2C1 CLK
	RCC->APB1ENR1 &= ~(RCC_APB1ENR1_I2C1EN);
	RCC->APB1ENR1 |=  (RCC_APB1ENR1_I2C1EN);
	//Select SystemCLK as I2C1 Clock Source
	RCC-> CCIPR &= ~(RCC_CCIPR_I2C1SEL);
	RCC-> CCIPR |=  (RCC_CCIPR_I2C1SEL_0);



	hi2c1.Instance = I2C1;
	hi2c1.Init.Timing = 0x10C09CD5;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN I2C1_Init 2 */

	/* USER CODE END I2C1_Init 2 */
}

/*
 * @brief I2C check Address
 */
bool i2c_I2C1_isSlaveAddressExist(uint8_t addrs, uint32_t timeout){

}

/*
 * @brief i2c Transmit(Master)
 */
bool i2c_I2C1_masterTransmit(uint8_t addrs, uint8_t *pData,uint8_t len, uint32_t timeout ){

}

/*
 * @brief i2c Recive(Master)
 */
bool i2c_I2C1_masterRecive(uint8_t addrs, uint8_t *pData,uint8_t len, uint32_t timeout ){

}
