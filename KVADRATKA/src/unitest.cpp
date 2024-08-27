#include <stdio.h>
#include <math.h>

#include "unitest.h"
#include "changer_str.h"

void UnitTest()
{
    for (int num_test = 0; num_test < TESTS_COUNT; num_test++) 
        RunTest(num_test);
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
        printf(CHANGE_STR_COLOR("COMPLETED", GREEN) CHANGE_STR_COLOR(" test %d", CYAN) "\n", num_test + 1);
}