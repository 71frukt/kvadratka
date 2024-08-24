#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solver.h"

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
        float sqrt_discr = (float)sqrt(discr);

        *root_1 = (- b - sqrt_discr) / (2 * a);
        *root_2 = (- b + sqrt_discr) / (2 * a);

        assert(!IsEqualF(*root_1, *root_2));

        return TWO_ROOTS; 
    }

    return ERROR_ROOTS;
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
            return "";
            break;
    }

    assert(0 && "Bad switch-case in GetCountOfRoots()");
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