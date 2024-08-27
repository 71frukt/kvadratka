#ifndef DRAW_SHREK
#define DRAW_SHREK

#include "TXLib.h"

/** 
    \defgroup draw_shrek_h Consts
    @{   
*/

namespace global
{

/// ���������� ������, ������� ��������� �� �����
const int shreks_count = 400;               
const int shreks_delta_time = 75;           // �����, ����� ������� �������� ��������� ���� (� �������������)

}

void DrawShrek(void);                       // �������, ��������� ���� ������ �� �����
/**
 @param window_size_x ������ ���� � �����
*/
void PrintRandomShreks(int window_size_x, int window_size_y, HDC shrek_icon, int num_shreks, int delta_time);   // �������, ��������� num_shreks ������ � ��������������� �����
                                                                                                                // �� ������ � ����������� (window_size_x X window_size_y) 
                                                                                                                // ����� ������ delta_time (� �������������)
/** 
    @}   
*/

#endif                                                                                                          


