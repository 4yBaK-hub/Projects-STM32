#ifndef _F24F_H
#define _F24F_H

#include <types.h>


// Шрифт пропорциональный, высота 24
#define f24_FLOAT_HEIGHT        24

// Кол-во символов в таблице шрифта
#define f24f_NOFCHARS           10


// Функция возвращает указатель на подтаблицу символа Char
uint8_t *f24f_GetCharTable(uint8_t Char);

#endif 
