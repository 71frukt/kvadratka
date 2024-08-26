#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "user_interaction.h"

bool GetInput(float *a, float *b, float *c)
{
    assert(a);
    assert(b);
    assert(c);
    assert(a != b || b != c || a != c);

    printf("\nEnter three coefficients (a b c) for the solution.\n");

    if (GetValue(a, b, c) == false) {
        printf("Incorrect input! Try again. \n");
        return false;
    }
    return true; 
}

bool GetValue(float *a, float *b, float *c)
{
    assert(a);
    assert(b);
    assert(c);
    assert(a != b && a != c && a != c);

    bool exit_val = false;

    if (scanf("%f %f %f", a, b, c) == 3)
        exit_val = true;
    else
        exit_val = false;

    exit_val = CleanBuffer();

    return exit_val;
}

bool CleanBuffer()
{
    bool success_clean = true;
    char curr_ch = 0;

    while ((curr_ch = (char)getchar()) != '\n')       //пропускаем остальной ввод, если он был
    {       
        if (!isspace(curr_ch)) 
            success_clean = false;
    } 

    return success_clean;
}

menu_code ExitMenu()
{
    char enter_ch = 0;

    while (true)
    {
        printf("\nEnter \'y\' if you want to continue or \'n\' to exit: ");
        scanf("%c", &enter_ch);

        if (CleanBuffer() == false) {         //если далее идут символы
            printf("Incorrect input.");
            continue;
        }

        if (tolower(enter_ch) == 'y')
            return MENU_CONTINUE;
        else if (tolower(enter_ch) == 'n')
            return MENU_EXIT;
        else
            printf ("Incorrect input.");    //если enter_ch не y и не n  
    }

    printf("Abnormal ExitMenu code %d", MENU_ERROR);
    return MENU_ERROR;
}
