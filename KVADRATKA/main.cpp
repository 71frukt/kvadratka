#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

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



int main()
{
    float a = NAN;
    float c = NAN;
    float b = NAN;
    float root_1 = NAN;
    float root_2 = NAN;
    
    printf("\nThis program solves a quadratic equation. \n");

    while (true)
    {  
        if (GetInput(&a, &b, &c) == false)
            continue;
        
        count_of_roots n_roots = general_solve_equation(a, b, c, &root_1, &root_2);
        PrintSolve(n_roots, root_1, root_2);

        if (ExitMenu() == 0)
            break;
    }

    printf("The program is completed. \n");
    return 0;
}

bool GetInput(float *a, float *b, float *c)
{
    printf("\nEnter three coefficients (a b c) for the solution.\n");

    if(GetValue(a, b, c) == false){
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

    while ((curr_ch = getchar()) != '\n')       //пропускаем остальной ввод, если он был
    {       
        if(!isspace(curr_ch)){
            success_clean = false;
        }    
    } 

    return success_clean;
}

count_of_roots general_solve_equation(float a, float b, float c, float *root_1, float *root_2)
{
    assert(root_1);
    assert(root_2);
    assert(root_1 != root_2);

    count_of_roots n_roots = NO_ROOTS;
    if (IsZeroF(a)) {                                  //if (a == 0)
        n_roots = solve_linear_equation(b, c, root_1);
        *root_2 = NAN;
    }
    else    //введённое квадратное уравнение всё-таки действительно квадратное   
        n_roots = solve_quadratic_equation(a, b, c, root_1, root_2);    //количество корней
    
    return n_roots;
}

count_of_roots solve_linear_equation(float b, float c, float *root_1)
{
    assert(root_1);

    if (IsZeroF(b) && IsZeroF(c))             //if (b == 0 && c == 0)
        return INFIN_ROOTS;
    else if (IsZeroF(b))                        //else if (b == 0 && c != 0)
        return NO_ROOTS;        
    else {                                        //else if (b != 0 && c != 0)
        *root_1 = - c / b;
        return ONE_ROOT;        
    }   

    return ERROR_ROOTS;
}

count_of_roots solve_quadratic_equation(float a, float b, float c, float *root_1, float *root_2)
{
    assert(root_1);
    assert(root_2);
    assert(root_1 != root_2);

    float Discr = b * b - 4 * a * c; 

    if (Discr < 0)
        return NO_ROOTS;

    else if (IsZeroF(Discr)) {        //if D == 0
        *root_1 = - b / (2 * a);
        *root_2 = *root_1;

        return ONE_ROOT; 
    }

    else {
        float sqrt_Discr = sqrt(Discr);

        *root_1 = (- b - sqrt_Discr) / (2 * a);
        *root_2 = (- b + sqrt_Discr) / (2 * a);

        assert(IsDifferentF(*root_1, *root_2));

        return TWO_ROOTS; 
    }

    return ERROR_ROOTS;
}

void PrintSolve(count_of_roots n_roots, float root_1, float root_2)
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

int ExitMenu()
{
    char enter_ch = 0;

    while (true)
    {
        printf("\nEnter \'y\' if you want to continue or \'n\' to exit: ");
        scanf("%c", &enter_ch);


        if(CleanBuffer() != true){         //если далее идут символы
            printf("Incorrect input.");
            continue;
        }

        if ( tolower(enter_ch) == 'y' )
            return 1;
        else if ( tolower(enter_ch) == 'n' )
            return 0;
        else
            printf ("Incorrect input.");    //если enter_ch не y и не n  
    }
}


bool IsDifferentF(float num_1, float num_2)
{
    return (fabs(num_1 - num_2) > LOWCONST);
}

bool IsZeroF(float num)
{
    return !IsDifferentF(num, 0);
}
