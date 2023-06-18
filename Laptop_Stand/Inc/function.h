/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"
#include "usb_device.h"
#include "gpio.h"
#include "tim.h"
#include "usbd_cdc_if.h"
#include "st77xx.h"
#include "dispcolor.h"
#include "font.h"
#include "string.h"
#include "stdio.h"

#define OK              1
#define ERROR           0

#define HEAD_1          170
#define HEAD_2          255


/* USER CODE BEGIN Prototypes */
void update_display(void);
void clear_numbers(void);
void update_loadbars(uint8_t cpu, uint8_t mem);
void drive_FAN(uint8_t temp);
void Set_template(void);
uint16_t Get_CRC(void);
uint8_t Check_CRC(void);
void Convert_data_to_State(uint8_t num, uint8_t k);
void handling(void);
/* USER CODE END Prototypes */