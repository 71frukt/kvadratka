#ifndef SOLVER_H
#define SOLVER_H

enum count_of_roots         // перечисление возможного количества корней
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFIN_ROOTS,
    ERROR_ROOTS             // ошибка получени€ количества корней
};

const float LOWCONST = 0.001f;          // «адает точность сравнени€ чисел

count_of_roots GeneralSolveEquation(const float a, const  float b, const float c, float *root_1, float *root_2);  // Hешает введЄнное уравнение и возвращает количество корней
count_of_roots SolveLinearEquation(const float b, const float c, float *root_1);                                  // –ешает уравнение при a == 0 (линейное или при всех коефф. == 0)
count_of_roots SolveQuadraticEquation(const float a, const float b, const float c, float *root1, float *root2);   // –ешает квадратное уравнение и возвращает количество корней

void PrintSolve(count_of_roots n_roots, float root_1, float root_2);                      // ¬ыводит решение уравнени€
    
const char *GetCountOfRoots(count_of_roots n_roots);                                      // ¬озвращает указатель на строку, в которой записано количество корней

bool IsEqualF(float num_1, float num_2);                                                  // ¬озвращает true, если числа равны с точностью до LOWCONST и false, если не равны
bool IsZeroF(float num);                                                                  // ¬озвращает true, если число равно нулю с точностью до LOWCONST и false, если не равно

#endif
