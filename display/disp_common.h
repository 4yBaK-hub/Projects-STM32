#ifndef _DISP_COMMON_H
#define _DISP_COMMON_H

#include <types.h>

// ��������� �������������� ������� �������
void disp_Init(uint8_t Width, uint8_t Height);
// ��������� ������������� ������� �������
void disp_SetBrightness(uint8_t Value);
// ��������� ������� ����� (����������� ������)
void disp_ClearScreen(void);
// ��������� ���������� 1 ������� �������
void disp_DrawPixel(int16_t x, int16_t y, uint16_t color);
// ��������� ���������� �������������� ������ color
void disp_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
// ��������� ����������� ����� ������ color
void disp_FillScreen(uint16_t color);
// ��������� ���������� ������������� ������� �� ������ (������� ���������� ������� Y, X
void disp_DrawPartYX(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pBuff);
// ��������� ���������� ������������� ������� �� ������ (������� ���������� ������� X, Y
void disp_DrawPartXY(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pBuff);


#endif