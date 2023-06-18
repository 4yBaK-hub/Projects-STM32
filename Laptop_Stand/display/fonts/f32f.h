#ifndef _F32F_H
#define _F32F_H

#include <types.h>


// Шрифт пропорциональный, высота 32
#define f32_FLOAT_HEIGHT        32

// Кол-во символов в таблице шрифта
#define f32f_NOFCHARS           10


// Функция возвращает указатель на подтаблицу символа Char
uint8_t *f32f_GetCharTable(uint8_t Char);

#endif 
