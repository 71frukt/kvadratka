#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "user_interaction.h"
#include "changer_str.h"

bool GetInput(float *a, float *b, float *c)
{
    assert(a);
    assert(b);
    assert(c);
    assert(a != b || b != c || a != c);

    printf(CHANGE_STR_COLOR("\nEnter three coefficients (a b c) for the solution.\n", GREEN));

    if (GetValue(a, b, c) == false) {
        printf(CHANGE_STR_COLOR("Incorrect input! Try again. \n", YELLOW));
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
        printf("\nEnter " CHANGE_STR_COLOR("y", GREEN) " if you want to continue or " 
                CHANGE_STR_COLOR("n", RED) " to exit: ");

        scanf("%c", &enter_ch);

        if (CleanBuffer() == false) {         //если далее идут символы
            printf(CHANGE_STR_COLOR("Incorrect input", YELLOW));
            continue;
        }

        if (tolower(enter_ch) == 'y')
            return MENU_CONTINUE;
        else if (tolower(enter_ch) == 'n')
            return MENU_EXIT;
        else
            printf(CHANGE_STR_COLOR("Incorrect input", YELLOW));
    }

    printf("Abnormal ExitMenu code %d", MENU_ERROR);
    return MENU_ERROR;
}