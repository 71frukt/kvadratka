#ifndef DRAW_SHREK
#define DRAW_SHREK

#include "TXLib.h"

/** 
    \defgroup draw_shrek_h Consts
    @{   
*/

namespace global
{

/// Количество шреков, которое выведется на экран
const int shreks_count = 400;               
const int shreks_delta_time = 75;           // Время, через которое выведеся следующий шрек (в миллисекундах)

}

void DrawShrek(void);                       // Функция, выводящая всех шреков на экран
/**
 @param window_size_x Размер окна в длину
*/
void PrintRandomShreks(int window_size_x, int window_size_y, HDC shrek_icon, int num_shreks, int delta_time);   // Функция, выводящая num_shreks шреков в псевдорандомном месте
                                                                                                                // на экране с разрешением (window_size_x X window_size_y) 
                                                                                                                // через каждые delta_time (в миллисекундах)
/** 
    @}   
*/

#endif                                                                                                          


