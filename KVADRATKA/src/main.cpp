#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "unitest.h"
#include "user_interaction.h"
#include "unitest.h"
#include "flags_work.h"
#include "changer_str.h"

void StandartProgRun();

int main(const int argc, const char *argv[])
{
    bool todo_stand_prog = true;
    bool flag_includes[FLAGS_COUNT] = {};
    
    //strcpy (argv[1], "SENYA KOLBASENYA");

    if (GetCmdFlags(argc, argv, flag_includes, FLAGS_COUNT) == false) { 
        printf(CHANGE_STR_COLOR("Incorrect flag", RED));
        return 0;
    }

    HandleFlags(flag_includes, FLAGS_COUNT, &todo_stand_prog);

    if(todo_stand_prog)
        StandartProgRun();

    return 0;
}

void StandartProgRun()
{
    float a = NAN;
    float c = NAN;
    float b = NAN;
    float root_1 = NAN;
    float root_2 = NAN;

    printf(CHANGE_STR_COLOR("\nThis program solves a quadratic equation. \n", GREEN)); 

    while (true)
    {  
        if (GetInput(&a, &b, &c) == false)
            continue;
        
        count_of_roots n_roots = GeneralSolveEquation(a, b, c, &root_1, &root_2);
        PrintSolve(n_roots, root_1, root_2);

        menu_code code = ExitMenu();
        if (code == MENU_EXIT)
            break;
        else if (code == MENU_CONTINUE)
            continue;
    }
    
    printf(CHANGE_STR_COLOR("The program is completed. \n", BLUE));
}



