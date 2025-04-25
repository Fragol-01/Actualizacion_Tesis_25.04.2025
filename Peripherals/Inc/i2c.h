/*
 * i2c.h
 *
 *  Created on: 23 abr. 2025
 *      Author: DANNY
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"
#include <gpio.h>

extern I2C_HandleTypeDef hi2c1;

/*
 * @brief I2C GPIO Configuration PA9(D1)->SCL and PA10(D0)->SDA
 */
void i2c_I2C1_GPIO_Config(void);

/*
 * @brief I2C Peripheral Config
 */
void i2c_I2C1_Config(void);

/*
 * @brief I2C check Address
 */
bool i2c_I2C1_isSlaveAddressExist (uint8_t addrs, uint32_t timeout);

/*
 * @brief i2c Transmit(Master)
 */
bool i2c_I2C1_masterTransmit(uint8_t addrs, uint8_t *pData,uint8_t len, uint32_t timeout );

/*
 * @brief i2c Recive(Master)
 */
bool i2c_I2C1_masterRecive(uint8_t addrs, uint8_t *pData,uint8_t len, uint32_t timeout );




#endif /* INC_I2C_H_ */
