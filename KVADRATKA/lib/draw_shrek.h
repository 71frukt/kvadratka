#ifndef DRAW_SHREK
#define DRAW_SHREK

#include "TXLib.h"

const int shreks_count = 400;
const int shreks_delta_time = 75;  //в миллисекундах 

void DrawShrek(void);
void PrintRandomShreks(int window_size_x, int window_size_y, HDC shrek_icon, int num_shreks, int delta_time);

#endif