#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "kvadratka.h"


int main(int argc, char *argv[])
{
    bool todo_stand_prog = true;
    bool flag_includes[FLAGS_COUNT] = {};

    if (GetCmdFlags(argc, argv, flag_includes, FLAGS_COUNT) == false) { 
        printf("Incorrect flag");
        return 0;
    }

    HandleFlags(flag_includes, FLAGS_COUNT, &todo_stand_prog);

    if(todo_stand_prog)
        StandartProgRun();

    return 0;
}

bool GetCmdFlags(int arg_c, char *arg_v[], bool flag_includes[], int flags_count)
{
    assert(arg_v);

    for (int i = 1; i < arg_c; i++)
    {
        bool curr_valid = false;

        for (int j = 0; j < flags_count; j++)
        {
            if (strcmp(arg_v[i], flags_funcs[j].name) == 0) {
                flag_includes[j] = true;
                curr_valid = true;
            }
        }

        if (!curr_valid)
            return false;
    }

    return true;
}

void HandleFlags(bool flag_includes[], int flags_count, bool *todo_stand_prog)
{
    for (int i = 0; i < FLAGS_COUNT; i++) {
        if (flag_includes[i]) {
            flags_funcs[i].function();

            if(flags_funcs[i].do_standart_prog == false)
                *todo_stand_prog = false;
        }
    } // TODO: make as HandleFlag
}

void StandartProgRun()
{
    float a = NAN;
    float c = NAN;
    float b = NAN;
    float root_1 = NAN;
    float root_2 = NAN;

    printf("\nThis program solves a quadratic equation. \n"); // TODO: make as StandartModeRun

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
    
    printf("The program is completed. \n");
}



void UnitTest()
{
    for (int num_test = 0; num_test < FLAGS_COUNT; num_test++) 
        RunTest(num_test);
    
}

void PrintHelp()
{
    printf("\n---------------------------- HELP -----------------------------------\n"
            "For solving the quadratic equation of the form \"ax^2 + bx + c = 0\" \n"
            "input coefs a, b, c in the form \"1 3 -9\"\n"
            "---------------------------------------------------------------------\n\n");
}

void RunTest(int num_test)
{
    float x1 = NAN;
    float x2 = NAN;

    test_values test = tests[num_test];

    count_of_roots n_roots = GeneralSolveEquation(test.a, test.b, test.c, &x1, &x2);

    if (!IsEqualF(n_roots, test.n_roots_exp) || !IsEqualF(x1, test.x1_exp) || !IsEqualF(x2, test.x2_exp)) 
    {
        printf("Error test %d: a = %g, b = %g, c = %g, x1 = %g, x2 = %g, n_roots = %s \n"
               "Expected: x1 = %g, x2 = %g, n_roots = %s \n\n",
                (num_test + 1), test.a, test.b, test.c, x1, x2, GetCountOfRoots(n_roots), test.x1_exp, test.x2_exp, GetCountOfRoots(test.n_roots_exp));
    }
    else 
        printf("COMPLETED test %d \n", num_test + 1);
}

bool GetInput(float *a, float *b, float *c)
{
    // TODO: put asserts
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

count_of_roots GeneralSolveEquation(const float a, const float b, const float c, float *root_1, float *root_2)
{
    assert(root_1);
    assert(root_2);
    assert(root_1 != root_2);

    count_of_roots n_roots = ERROR_ROOTS;

    if (IsZeroF(a)) {                                  //if (a == 0)
        n_roots = SolveLinearEquation(b, c, root_1);
        *root_2 = NAN;
    }
    else    //введённое квадратное уравнение всё-таки действительно квадратное   
        n_roots = SolveQuadraticEquation(a, b, c, root_1, root_2);    //количество корней
    
    return n_roots;
}

count_of_roots SolveLinearEquation(const float b, const float c, float *root_1)
{
    assert(root_1);

    if (IsZeroF(b) && IsZeroF(c))               //if (b == 0 && c == 0)
        return INFIN_ROOTS;
    else if (IsZeroF(b))                        //else if (b == 0 && c != 0)
        return NO_ROOTS;        
    else {                                      //else if (b != 0 && c != 0)
        *root_1 = - c / b;
        return ONE_ROOT;        
    }   

    return ERROR_ROOTS;
}

count_of_roots SolveQuadraticEquation(const float a, const float b, const float c, float *root_1, float *root_2)
{
    assert(root_1);
    assert(root_2);
    assert(root_1 != root_2);

    float discr = b * b - 4 * a * c; 

    if (discr < 0)
        return NO_ROOTS;

    else if (IsZeroF(discr)) {        //if D == 0
        *root_1 = - b / (2 * a);
        *root_2 = NAN;

        return ONE_ROOT; 
    }

    else {                              //if D > 0
        float sqrt_discr = sqrt(discr);

        *root_1 = (- b - sqrt_discr) / (2 * a);
        *root_2 = (- b + sqrt_discr) / (2 * a);

        assert(!IsEqualF(*root_1, *root_2));

        return TWO_ROOTS; 
    }

    return ERROR_ROOTS;
}

void PrintSolve(count_of_roots n_roots, const float root_1, const float root_2)
{
    switch (n_roots)
    {
        case NO_ROOTS:
            printf("The equation has no roots! \n");
            break;
        case ONE_ROOT:
            printf("The equation has a single root = %.2f \n", root_1);
            break;
        case TWO_ROOTS:
            printf("The introduced equation is solver. It has two roots: %.2f, %.2f \n", root_1, root_2);
            break;
        case INFIN_ROOTS:
            printf("All coefficients are zero. Root is any number.\n");
            break; 
        case ERROR_ROOTS:                                                            
        default:
            printf("Incorrect n_roots value!");
            break;
    }
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

    printf("Abnormal ExitMenu code");
    return MENU_ERROR;
}

const char *GetCountOfRoots(count_of_roots n_roots)
{
    switch (n_roots)
    {
        case NO_ROOTS:
            return "NO_ROOTS";
            break;
        case ONE_ROOT:
            return "ONE_ROOT";
            break;
        case TWO_ROOTS:
            return "TWO_ROOTS";
            break;
        case INFIN_ROOTS:
            return "INFIN_ROOTS";
            break;
        case ERROR_ROOTS: 
        default:
            printf("Error of running test! Count of roots is incorrect \n");
            // return here
            break;
    }
    //put assert(0 && "Bad switch-case in GetCountOfRoots()")
    return "";
}

bool IsEqualF(float num_1, float num_2)
{  
    if (isnan(num_1) && isnan(num_2))
        return true;
    else 
        return (fabs(num_1 - num_2) < LOWCONST);
}

bool IsZeroF(float num)
{
    return IsEqualF(num, 0);
}


