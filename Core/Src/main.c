///* USER CODE BEGIN Header */
///**
// ******************************************************************************
// * @file           : main.c
// * @brief          : Main program body
// ******************************************************************************
// * @attention
// *
// * Copyright (c) 2024 STMicroelectronics.
// * All rights reserved.
// *
// * This software is licensed under terms that can be found in the LICENSE file
// * in the root directory of this software component.
// * If no LICENSE file comes with this software, it is provided AS-IS.
// *
// ******************************************************************************
// */
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"
//#include <gpio.h>
//#include <uart.h>
//#include <spi.h>
//#include "fatfs.h"
//
///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//
///* USER CODE END Includes */
//
///* Private typedef -----------------------------------------------------------*/
///* USER CODE BEGIN PTD */
//
///* USER CODE END PTD */
//
///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
//
///* USER CODE END PD */
//
///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */
//
///* USER CODE END PM */
//
///* Private variables ---------------------------------------------------------*/
//SPI_HandleTypeDef hspi1;
//uint32_t systemClock=72000000;
////FatFs variables
//FRESULT fresult;
//FATFS fs;
//DWORD freeClusters;
//FATFS *pFatFs;
//uint32_t total_size,free_space;;
//FIL file;
//UINT readBytes=0;
//UINT writeBytes=0;
//#define BUFFER_SIZE 128
//char buffer[BUFFER_SIZE];  // to store strings..
//int bufsize (char *buf)
//{
//	int i=0;
//	while (*buf++ != '\0') i++;
//	return i;
//}
//
//void clear_buffer (void)
//{
//	for (int i=0; i<BUFFER_SIZE; i++) buffer[i] = '\0';
//}
//
///* USER CODE BEGIN PV */
//
///* USER CODE END PV */
//
///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_SPI1_Init(void);
///* USER CODE BEGIN PFP */
//
///* USER CODE END PFP */
//
///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */
//
///* USER CODE END 0 */
//
///**
// * @brief  The application entry point.
// * @retval int
// */
//int main(void)
//{
//
//	/* USER CODE BEGIN 1 */
//
//	/* USER CODE END 1 */
//
//	/* MCU Configuration--------------------------------------------------------*/
//
//	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//	HAL_Init();
//
//	/* USER CODE BEGIN Init */
//
//	/* USER CODE END Init */
//
//	/* Configure the system clock */
//	SystemClock_Config();
//
//	/* USER CODE BEGIN SysInit */
//
//	/* USER CODE END SysInit */
//
//	/* Initialize all configured peripherals */
//	spi_GPIO_config();
//	gpio_LED_config();
//	uart_UART2_GPIO_config();
//	uart_UART2_config(systemClock);
//	MX_SPI1_Init();
//	MX_FATFS_Init();
//	/* USER CODE BEGIN 2 */
//	//Mount SD Card
//	fresult=f_mount(&fs, "/", 1);
//	if (fresult != FR_OK)
//	{
//		printf("Failed to mount SD card to FatFs\r\n");
//	}
//	else
//	{
//		printf("Successfully Mounted SD card\r\n");
//	}
//	//Print status
//	printf("SD card result = %d\r\n",fresult);
////	//Read SD card size and free space
////	fresult=f_getfree("",&freeClusters, &pFatFs);
////    total_size= (uint32_t)((pFatFs->n_fatent - 2) * pFatFs->csize * 0.5);
////    free_space =(uint32_t) (freeClusters * pFatFs->csize * 0.5);
////	//Print status
////	printf("SD card result = %d\r\n",fresult);
////    //SD card clusters have 512Bytes
////    //For that we want the number of clusters/2
////    //(number of 1024bytes(1KB) clusters)
////    printf("%lu KB total drive space.\r\n",total_size);
////    printf("%lu KB available space.\r\n",free_space);
//    //Open a file for r/w
//    fresult=f_open(&file, "Test2.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE | FA_CREATE_ALWAYS );
//	if (fresult != FR_OK)
//	{
//		printf("Failed to open a file\r\n");
//	}
//	else
//	{
//		printf("Successfully opened file\r\n");
//		//Write to the file
//		strcpy (buffer, "Puedo trabajar con 18MHz el baud rate del SPI!!!.");
//		fresult=f_write(&file, buffer, bufsize(buffer), &writeBytes);
//		//f_puts("This is a test in STM32, getting started uSD Card.", &file);
//		if (fresult != FR_OK)
//			{
//				printf("Failed to write a file in the SD card \r\n");
//			}
//			else
//			{
//				printf("The file was written successfully\r\n");
//			  	/* Close file */
//			  	f_close(&file);
//			  	// Clearing buffer to show that result obtained is from the file
//			  	clear_buffer();
//				/* Open file to read */
//			  	fresult = f_open(&file, "Test2.txt", FA_READ);
//				if (fresult != FR_OK)
//				{
//					printf("Failed to open a file for read\r\n");
//				}
//				else
//				{
//					printf("Successfully opened file for read\r\n");
//					//Read data from the file
//					fresult=f_read(&file, buffer, f_size(&file), &readBytes);
//					if (fresult != FR_OK)
//					{
//						printf("Failed to read a file in the SD card \r\n");
//					}
//					else
//					{
//						printf("The file was read successfully\r\n");
//						printf(buffer);
//						printf("\n");
//					}
//				}
//			}
//		f_close(&file);
//		clear_buffer();
//	/* USER CODE END 2 */
//
//	/* Infinite loop */
//	/* USER CODE BEGIN WHILE */
//	while (1)
//	{
//		/* USER CODE END WHILE */
//        gpio_LED_toggleGreen();
//        HAL_Delay(250);
//		/* USER CODE BEGIN 3 */
//	}
//	/* USER CODE END 3 */
//}}
//
///**
// * @brief System Clock Configuration
// * @retval None
// */
//void SystemClock_Config(void)
//{
//	  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//
//	  /** Configure the main internal regulator output voltage
//	  */
//	  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
//	  {
//	    Error_Handler();
//	  }
//
//	  /** Initializes the RCC Oscillators according to the specified parameters
//	  * in the RCC_OscInitTypeDef structure.
//	  */
//	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
//	  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
//	  RCC_OscInitStruct.MSICalibrationValue = 0;
//	  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
//	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
//	  RCC_OscInitStruct.PLL.PLLM = 1;
//	  RCC_OscInitStruct.PLL.PLLN = 36;
//	  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
//	  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
//	  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
//	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//	  {
//	    Error_Handler();
//	  }
//
//	  /** Initializes the CPU, AHB and APB buses clocks
//	  */
//	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//
//	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
//	  {
//	    Error_Handler();
//	  }
//}
//
///**
// * @brief SPI1 Initialization Function
// * @param None
// * @retval None
// */
//static void MX_SPI1_Init(void)
//{
//
//	/* USER CODE BEGIN SPI1_Init 0 */
//
//	/* USER CODE END SPI1_Init 0 */
//
//	/* USER CODE BEGIN SPI1_Init 1 */
//
//	/* USER CODE END SPI1_Init 1 */
//	/* SPI1 parameter configuration*/
//	hspi1.Instance = SPI1;
//	hspi1.Init.Mode = SPI_MODE_MASTER;
//	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
//	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
//	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
//	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
//	hspi1.Init.NSS = SPI_NSS_SOFT;
//	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
//	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
//	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
//	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
//	hspi1.Init.CRCPolynomial = 7;
//	hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
//	hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
//	if (HAL_SPI_Init(&hspi1) != HAL_OK)
//	{
//		Error_Handler();
//	}
//	/* USER CODE BEGIN SPI1_Init 2 */
//
//	/* USER CODE END SPI1_Init 2 */
//
//}
//
///**
// * @brief GPIO Initialization Function
// * @param None
// * @retval None
// */
//
//
//void Error_Handler(void)
//{
//	/* USER CODE BEGIN Error_Handler_Debug */
//	/* User can add his own implementation to report the HAL error return state */
//	__disable_irq();
//	while (1)
//	{
//	}
//	/* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef  USE_FULL_ASSERT
///**
// * @brief  Reports the name of the source file and the source line number
// *         where the assert_param error has occurred.
// * @param  file: pointer to the source file name
// * @param  line: assert_param error line source number
// * @retval None
// */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//	/* USER CODE BEGIN 6 */
//	/* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//	/* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */
