#include "TXLib.h"
#include <stdio.h>
#include "draw_shreck.h"

void DrawShreck()
{
    HDC shreck = txLoadImage("Images/shreck.bmp");

    int sizeX = txGetExtentX(shreck);
    int sizeY = txGetExtentY(shreck);
    
    txCreateWindow(sizeX, sizeY);
    txAlphaBlend(0, 0, shreck);
}