#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

const float LOWCONST = 0.0001;
const int INFIN_ROOTS = 3;

bool get_value(float *a, float *b, float *c);                                           //true, если принял все значения и false, если не все
int general_solve_equation(float a, float b, float c, float *root_1, float *root_2);    //решает введённое уравнение и возвращает количество корней
int solve_linear_equation(float b, float c, float *root_1);                             //решает уравнение при a == 0 (линейное или все коэффициенты == 0)
int solve_quadratic_equation(float a, float b, float c, float *root1, float *root2);    //решает квадратное уравнение и возвращает количество корней
void print_solve(int n_roots, float root_1, float root_2);                              //выводит решение 
int exit_menu();                                                                        //позволяет выбрать выйти из программы или остаться в ней
bool clean_buffer();
bool is_different_F(float num_1, float num_2);
bool is_zero_F(float num);

// TODO refactoring code

int main()
{
    float a = NAN;
    float c = NAN;
    float b = NAN;
    float root_1 = NAN;
    float root_2 = NAN;
    
    printf("\nThis program solves a quadratic equation. \nEnter three coefficients (a b c) for the solution.\n");

    bool is_getted = false;
    while (true)
    {   
        is_getted = get_value(&a, &b, &c);
        if(!is_getted){
            printf("Incorrect input! Try again. \nEnter three coefficients (a b c) for the solution.\n");
            continue;
        }
        
        int n_roots = general_solve_equation(a, b, c, &root_1, &root_2);
        print_solve(n_roots, root_1, root_2);

        if (exit_menu() == 0)
            break;
        else
            printf("\nEnter three coefficients (a b c) for the solution.\n");
    }

    printf("The program is completed. \n");
    return 0;
}


bool get_value(float *a, float *b, float *c)
{
    assert(b);
    assert(c);
    assert( a != b && a != c && a != c );

    int exit_val = false;

    if (scanf("%f %f %f", a, b, c) == 3)
        exit_val = true;
    else
        exit_val = false;

    exit_val = clean_buffer();

    return exit_val;
}


int general_solve_equation(float a, float b, float c, float *root_1, float *root_2)
{
    assert(root_1);
    assert(root_2);
    assert(root_1 != root_2);

    int n_roots = 0;
    if (is_zero_F(a)){                                  //if (a == 0)
        n_roots = solve_linear_equation(b, c, root_1);
        *root_2 = NAN;
    }
    else    //введённое квадратное уравнение всё-таки действительно квадратное   
        n_roots = solve_quadratic_equation(a, b, c, root_1, root_2);    //количество корней
    
    return n_roots;
}

int solve_linear_equation(float b, float c, float *root_1)
{
        if (is_zero_F(b) && is_zero_F(c))             //if (b == 0 && c == 0)
            return INFIN_ROOTS;
        else if (is_zero_F(b))                        //else if (b == 0 && c != 0)
            return 0;        // TODO magic const
        else {                                        //else if (b != 0 && c != 0)
            *root_1 = - c / b;
            return 1;        // TODO magic const
        }   
}

int solve_quadratic_equation(float a, float b, float c, float *root_1, float *root_2)
{
    assert(root_1);
    assert(root_2);
    assert(root_1 != root_2);

    float Discr = b * b - 4 * a * c; // TODO rename variable D

    if (Discr < 0)
        return 0;

    else if (is_zero_F(Discr)) {        //if D == 0
        *root_1 = - b / (2 * a);
        *root_2 = *root_1;

        return 1; // magic const
    }

    else {
        float sqrt_Discr = sqrt(Discr);

        *root_1 = (- b - sqrt_Discr) / (2 * a);
        *root_2 = (- b + sqrt_Discr) / (2 * a);

        //assert(0 /*change me*/);

        return 2; // magic const
    }
}

void print_solve(int n_roots, float root_1, float root_2)
{
    switch (n_roots)
    {
        case 0:
            printf("The equation has no roots! \n");
            break;
        case 1:
            printf("The equation has a single root = %.2f \n", root_1);
            break;
        case 2:
            printf("The introduced equation is solver. It has two roots: %.2f, %.2f \n", root_1, root_2);
            break;
        case INFIN_ROOTS:
            printf("All coefficients are zero. Root is any number.\n");
            break;                                                             
        default:
            printf("Incorrect n_roots value!");
            break;
    }
}

int exit_menu()
{
    char enter_ch = 0;

    while (true)
    {
        printf("\nEnter Y if you want to continue or N to exit: ");
        scanf("%c", &enter_ch);


        if(clean_buffer() != true){         //если далее идут символы
            printf("Incorrect input.");
            continue;
        }

        if ( toupper(enter_ch) == 'Y' )
            return 1;
        else if ( toupper(enter_ch) == 'N' )
            return 0;
        else
            printf ("Incorrect input.");    //если enter_ch не Y и не N  
    }
}

bool clean_buffer()
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

bool is_different_F(float num_1, float num_2)
{
    return (fabs(num_1 - num_2) < LOWCONST);
}

bool is_zero_F(float num)
{
    return is_different_F(num, 0);
}