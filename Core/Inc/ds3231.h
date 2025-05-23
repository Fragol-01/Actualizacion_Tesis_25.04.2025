/*
 * i2c.h
 *
 *  Created on: 23 abr. 2025
 *      Author: DANNY
 */

#ifndef INC_DS3231_H_
#define INC_DS3231_H_

#include "main.h"

#define DS3231_ADDRESS  0xD0

#define DS3231_SEC      0x00
#define DS3231_MIN      0x01
#define DS3231_HOUR     0x02
#define DS3231_DAY      0x03
#define DS3231_DATE     0x04
#define DS3231_MONTH    0x05
#define DS3231_YEAR     0x06


/*
 * @brief configure and set date of RTC
 */
void DS3231_Set_Date_Time(uint8_t dy, uint8_t mth, uint8_t yr, uint8_t dw, uint8_t hr, uint8_t mn, uint8_t sc);
/*
 * @brief to get the Date of RTC ds3231
 */
void DS3231_Get_Date(uint8_t *day, uint8_t *mth, uint8_t *year, uint8_t *dow);
/*
 * @brief to get the time of RTC ds3231
 */
void DS3231_Get_Time(uint8_t *hr, uint8_t *min, uint8_t *sec);
/*
 * @brief to get the day of week of RTC ds3231
 */
void DS3231_Get_DayOfWeek(char* str);
/*
 * @brief to read in the rtc
 */
uint8_t DS3231_Read(uint8_t reg);
/*
 * @brief transform binary to decimal
 */
uint8_t DS3231_Bin_Bcd(uint8_t binary_value);
/*
 * @brief transform decimal to binary
 */
uint8_t DS3231_Bcd_Bin(uint8_t bcd_value);

#endif
