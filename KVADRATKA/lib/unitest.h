
#ifndef UNITEST_H
#define UNITEST_H

#include <math.h>
#include "solver.h"

const int TESTS_COUNT = 6;                                  // количество тестов

void UnitTest(void);                                        // Запускает юнитест, в котором находится TESTS_COUNT тестов
void RunTest(int num_test);                                 // Запускает конкретный тест с номером num_test

struct test_values                                          // Cтруктура, объявляющая значения тестов
{                                                           
    float a, b, c;                                          // a, b, c - коеффициенты уравнения
                                                            
    float x1_exp, x2_exp;                                   // x1_exp, x2_exp - ожидаемые верные корни
    count_of_roots n_roots_exp;                             // n_roots_exp - ожидаемое верное количество корней типа count_of_roots (перечисление возможного количества корней)
};

const struct test_values tests[TESTS_COUNT] =               // Массив структур типа test_values, содержащая значения TESTS_COUNT тестов
{ //  a,    b,   c,    x1_exp,  x2_exp, n_roots_exp 
    { 0.0,  0.0, 0.0,  NAN,     NAN,    INFIN_ROOTS },      // a == b == c == 0
    { 0.0,  0.0, 1.0,  NAN,     NAN,    NO_ROOTS    },      // a == b == 0, c != 0
    { 0.0,  1.0, 1.0, -1.0,     NAN,    ONE_ROOT    },      // a == 0, b != 0, c != 0

    { 1.0,  1.0, 1.0,  NAN,     NAN,    NO_ROOTS    },      // discr < 0
    { 1.0, -4.0, 4.0,  2.0,     NAN,    ONE_ROOT    },      // discr == 0
    { 1.0, -1.0,-2.0, -1.0,    2.0,     TWO_ROOTS   }       // discr > 0
};

#endif