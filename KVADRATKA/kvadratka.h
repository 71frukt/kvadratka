enum count_of_roots
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFIN_ROOTS,
    ERROR_ROOTS
};
count_of_roots general_solve_equation(float a, float b, float c, float *root_1, float *root_2);     //решает введённое уравнение и возвращает количество корней
count_of_roots solve_linear_equation(float b, float c, float *root_1);                              //решает уравнение при a == 0 (линейное или если все коэффициенты == 0)
count_of_roots solve_quadratic_equation(float a, float b, float c, float *root1, float *root2);     //решает квадратное уравнение и возвращает количество корней

bool GetInput(float *a, float *b, float *c);                                                        //получает ввод
bool GetValue(float *a, float *b, float *c);                                                        //true, если принял все значения и false, если не все
void PrintSolve(count_of_roots n_roots, float root_1, float root_2);                                           //выводит решение 
int ExitMenu();                                                                                     //позволяет выбрать выйти из программы или остаться в ней
bool CleanBuffer();
bool IsDifferentF(float num_1, float num_2);
bool IsZeroF(float num);

const float LOWCONST = 0.0001;