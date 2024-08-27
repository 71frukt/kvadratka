#include "TXLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "draw_shrek.h"

void DrawShrek()
{
    _txWindowStyle = WS_POPUP | WS_BORDER;

    int window_size_x = GetSystemMetrics (SM_CXSCREEN);
    int window_size_y = GetSystemMetrics (SM_CYSCREEN);

    printf("RAZMERI OKNA!! %d X %d\n", window_size_x, window_size_y);

    txCreateWindow(window_size_x, window_size_y);

    HDC shrek = txLoadImage("Images/shrek.bmp");

    PrintRandomShreks(window_size_x, window_size_y, shrek, global::shreks_count, global::shreks_delta_time);

    txDeleteDC (shrek);
}

void PrintRandomShreks(int window_size_x, int window_size_y, HDC shrek_icon, int num_shreks, int delta_time)
{
    int i = 0;
    while (i < num_shreks)
    {
        //printf("%ld\n", curr_time);

        int rand_X = rand() % window_size_x;
        int rand_Y = rand() % window_size_y;

        txAlphaBlend(rand_X, rand_Y, shrek_icon);

        Sleep(delta_time);

        i++;

        /*
        clock_t curr_time = clock();
        if(abs(curr_time % delta_time) < 3) {
            //printf("%ld\n", curr_time);
            int rand_X = rand() % window_size_x;
            int rand_Y = rand() % window_size_y;
            txAlphaBlend(rand_X, rand_Y, shrek_icon);
            i++;
        }            
        */
    }
}
