#include <math.h>

enum count_of_roots
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFIN_ROOTS,
    ERROR_ROOTS
};
count_of_roots GeneralSolveEquation(const float a, const  float b, const float c, float *root_1, float *root_2);     //решает введённое уравнение и возвращает количество корней
count_of_roots SolveLinearEquation(const float b, const float c, float *root_1);                              //решает уравнение при a == 0 (линейное или если все коэффициенты == 0)
count_of_roots SolveQuadraticEquation(const float a, const float b, const float c, float *root1, float *root2);     //решает квадратное уравнение и возвращает количество корней

enum menu_code
{
    MENU_ERROR = -1,
    MENU_EXIT = 0,
    MENU_CONTINUE = 1
};
menu_code ExitMenu();  

struct test_values
{
    float a, b, c;
    
    float x1_exp, x2_exp;
    count_of_roots n_roots_exp;
};


bool GetInput(float *a, float *b, float *c);                                                        //получает ввод
bool GetValue(float *a, float *b, float *c);                                                        //true, если принял все значения и false, если не все
void PrintSolve(count_of_roots n_roots, float root_1, float root_2);                                           //выводит решение 
bool CleanBuffer();
bool IsDifferentF(float num_1, float num_2);
bool IsGifferentNAN(float num_1, float num_2);
bool IsZeroF(float num);

void UnitTest(test_values tests[], int num_tests);
void RunTest(test_values test, int num_test);
const char *GetCountOfRoots(count_of_roots n_roots);
const double LOWCONST = 0.001;
const int ENUM_STR_LEN = 30;

struct test_values tests[] =
{ //  a,    b,   c,    x1_exp,  x2_exp, n_roots_exp 
    { 0.0,  0.0, 0.0,  NAN,     NAN,    INFIN_ROOTS },    // a == b == c == 0
    { 0.0,  0.0, 1.0,  NAN,     NAN,    NO_ROOTS },       // a == b == 0, c != 0
    { 0.0,  1.0, 1.0, -1.0,     NAN,    ONE_ROOT },       // a == 0, b != 0, c != 0
  
    { 1.0,  1.0, 1.0,  NAN,     NAN,    NO_ROOTS },       // discr < 0
    { 1.0, -4.0, 4.0,  2.0,     NAN,    ONE_ROOT },       // discr == 0
    { 1.0, -1.0,-2.0, -1.0,    2.0,     TWO_ROOTS }       // discr > 0
};


