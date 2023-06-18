
#ifndef _ST7735_H
#define _ST7735_H

#include <types.h>

// Битовые маски настройки цветности ST7789
#define ST7735_ColorMode_12bit  0x03
#define ST7735_ColorMode_16bit  0x05
#define ST7735_ColorMode_18bit  0x06

// Смещение матрицы относительно строк/столбцов контроллера
#define ST7735_X_Start          24
#define ST7735_Y_Start          0


// Процедура инициализации дисплея
void ST7735_Init(uint8_t Width, uint8_t Height);


#endif
