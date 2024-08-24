#ifndef SOLVER_H
#define SOLVER_H

enum count_of_roots
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFIN_ROOTS,
    ERROR_ROOTS
};

const float LOWCONST = 0.001f;

count_of_roots GeneralSolveEquation(const float a, const  float b, const float c, float *root_1, float *root_2);     //решает введённое уравнение и возвращает количество корней
count_of_roots SolveLinearEquation(const float b, const float c, float *root_1);                              //решает уравнение при a == 0 (линейное или если все коэффициенты == 0)
count_of_roots SolveQuadraticEquation(const float a, const float b, const float c, float *root1, float *root2);     //решает квадратное уравнение и возвращает количество корней
void PrintSolve(count_of_roots n_roots, float root_1, float root_2);                                           //выводит решение 
const char *GetCountOfRoots(count_of_roots n_roots);
bool IsEqualF(float num_1, float num_2);
bool IsZeroF(float num);

#endif
