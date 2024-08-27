#include <stdio.h>
#include "help.h"
#include "changer_str.h"

void PrintHelp()
{
    printf(CHANGE_STR_COLOR("\n---------------------------- HELP -----------------------------------\n", GREEN)
           CHANGE_STR_COLOR("For solving the quadratic equation of the form \"ax^2 + bx + c = 0\" \n", CYAN)
           CHANGE_STR_COLOR("input coefs a, b, c in the form \"1 3 -9\"\n", CYAN)
           CHANGE_STR_COLOR("---------------------------------------------------------------------\n\n", GREEN));
}