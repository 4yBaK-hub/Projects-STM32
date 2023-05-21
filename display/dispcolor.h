#ifndef _DISPCOLOR_H
#define _DISPCOLOR_H

#include <types.h>


// Список поддерживаемых дисплеев (контроллеров дисплеев)
#define DISPTYPE_st7735         1

// С каким типом дисплея будет работать модуль disp1color 
#define DISPCOLOR_type         DISPTYPE_st7735

#define RGB565(r, g, b)         (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

// Базовые цвета
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF


// Процедура инициализирует цветной дисплей
void dispcolor_Init(uint8_t Width, uint8_t Height);
// Процедура очищает экран (закрашивает чёрным)
void dispcolor_ClearScreen(void);
// Процедура устанавливает яркость дисплея
void dispcolor_SetBrightness(uint8_t Value);
// Процедура закрашивает экран цветом color
void dispcolor_FillScreen(uint16_t color);
// Процедура окрашивает 1 пиксель дисплея
void dispcolor_DrawPixel(int16_t X, int16_t Y, uint16_t color);
// Процедура рисует прямую линию на дисплее
void dispcolor_DrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
// Процедура рисует прямоугольник на дисплее
void dispcolor_DrawRectangle(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
// Процедура рисует закрашенный прямоугольник на дисплее
void dispcolor_DrawRectangleFilled(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t fillcolor);
// Процедура рисует окружность на дисплее. x0 и y0 - координаты центра окружности
void dispcolor_DrawCircle(int16_t x0, int16_t y0, int16_t radius, uint16_t color);
// Процедура рисует закрашенную окружность на дисплее. x0 и y0 - координаты центра окружности
void dispcolor_DrawCircleFilled(int16_t x0, int16_t y0, int16_t radius, uint16_t fillcolor);
// Процедура заполнения прямоугольной области из буфера
void dispcolor_DrawPartXY(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pBuff);
// Процедура заполнения прямоугольной области из буфера
void dispcolor_DrawPartYX(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pBuff);
// Функция вывода текста из строки Str на дисплей. Возвращает ширину строки в пикселях
int16_t dispcolor_DrawString(int16_t X, int16_t Y, uint8_t FontID, uint8_t *Str, uint16_t TextColor);
// Функция вывода текста из строки Str на дисплей. Возвращает ширину строки в пикселях
int16_t dispcolor_DrawString_Bg(int16_t X, int16_t Y, uint8_t FontID, uint8_t *Str, uint16_t TextColor, uint16_t BgColor);
// Процедура выводит на дисплей форматированную строку. Возвращает ширину строки в пикселях
int16_t dispcolor_printf(int16_t X, int16_t Y, uint8_t FontID, uint16_t TextColor, const char *args, ...);
// Процедура выводит на дисплей форматированную строку. Возвращает ширину строки в пикселях
int16_t dispcolor_printf_Bg(int16_t X, int16_t Y, uint8_t FontID, uint16_t TextColor, uint16_t BgColor, const char *args, ...);

uint8_t dispcolor_DrawChar(int16_t X, int16_t Y, uint8_t FontID, uint8_t Char, uint16_t TextColor);
uint8_t dispcolor_DrawChar_Bg(int16_t X, int16_t Y, uint8_t FontID, uint8_t Char, uint16_t TextColor, uint16_t BgColor);

#endif