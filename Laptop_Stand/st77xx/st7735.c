//------------------------------------------------------------------------------
#include "stm32f1xx_hal.h"
#include "spi.h"
#include "gpio.h"
#include "dispcolor.h"
#include "st77xx.h"
#include "st7735.h"
#include <stdarg.h>
#include <string.h>


//==============================================================================
// Процедура инициализации дисплея
//==============================================================================
void ST7735_Init(uint8_t Width, uint8_t Height)
{
  ST77xx_Width = Width;
  ST77xx_Height = Height;
  ST77xx_X_Start = ST7735_X_Start;
  ST77xx_Y_Start = ST7735_Y_Start;

  // Инициализация интерфейса SPI
  MX_SPI1_Init();
  
  // Задержка после подачи питания
  HAL_Delay(40);
 
  // Сброс дисплея
  ST77xx_HardReset();
  // Отправляем последовательность инициализирующих команд
  ST77xx_SoftReset();

  ST77xx_SleepMode(0);

  ST77xx_ColorModeSet(ST7735_ColorMode_16bit);
  HAL_Delay(500);

  ST77xx_MemAccessModeSet(1, 0, 0, 1);
  HAL_Delay(10);

  ST77xx_InversionMode(1);
  HAL_Delay(10);

  ST77xx_FillScreen(0);
  
  // Включаем подсветку
  st77xx_SetBL(100);

  ST77xx_DisplayPower(1);
  HAL_Delay(100);
}
//==============================================================================
