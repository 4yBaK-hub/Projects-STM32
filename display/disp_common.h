#ifndef _DISP_COMMON_H
#define _DISP_COMMON_H

#include <types.h>

// Процедура инициализирует цветной дисплей
void disp_Init(uint8_t Width, uint8_t Height);
// Процедура устанавливает яркость дисплея
void disp_SetBrightness(uint8_t Value);
// Процедура очищает экран (закрашивает чёрным)
void disp_ClearScreen(void);
// Процедура окрашивает 1 пиксель дисплея
void disp_DrawPixel(int16_t x, int16_t y, uint16_t color);
// Процедура заполнения прямоугольника цветом color
void disp_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
// Процедура закрашивает экран цветом color
void disp_FillScreen(uint16_t color);
// Процедура заполнения прямоугольной области из буфера (порядок заполнения сектора Y, X
void disp_DrawPartYX(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pBuff);
// Процедура заполнения прямоугольной области из буфера (порядок заполнения сектора X, Y
void disp_DrawPartXY(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pBuff);


#endif