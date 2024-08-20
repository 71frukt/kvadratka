#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float LOWCONST = 0.0001;
const int INFIN_ROOTS = 3;

int get_value(float *a, float *b, float *c);                                            //записывает полученный ввод и возвращает 1, если принял все значения и 0, если не все
int general_solve_equation(float a, float b, float c, float *root_1, float *root_2);    //решает введённое уравнение и возвращает количество корней
int solve_quadratic_equation(float a, float b, float c, float *root1, float *root2);    //решает квадратное уравнение и возвращает количество корней
void print_solve(int n_roots, float root_1, float root_2);                              //выводит решение 
int menu();

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float root_1 = 0;
    float root_2 = 0;
    
    printf("\nThis program solves a quadratic equation. \nEnter three coefficients (a b c) for the solution.\n");

    //int flag = get_value(&a, &b, &c);
    while (get_value(&a, &b, &c) > 0)
    {   
        int n_roots = general_solve_equation(a, b, c, &root_1, &root_2);
        print_solve(n_roots, root_1, root_2);
        
        if (menu() == 0)
        {
            printf("The program is completed\n");
            return 0;
        }
        else
            printf("Enter three coefficients (a b c) for the solution.\n");
    }
    
}


int get_value(float *a, float *b, float *c)
{
    int exit_val = 0;
    if (scanf("%f %f %f", a, b, c) == 3)
        exit_val = 1;
    else
        exit_val = 0;

    char curr_ch = 0;
    while ((curr_ch = getchar()) != '\n')     //пропускаем остальной ввод, если он был
        continue;    

    return exit_val;
}


int general_solve_equation(float a, float b, float c, float *root_1, float *root_2)
{
    int n_roots = 0;
    if (fabs(a) < LOWCONST)
        {
            if (fabs(b) < LOWCONST && fabs(c) < LOWCONST)
                n_roots = INFIN_ROOTS;

            else if (fabs(b) < LOWCONST && fabs(c) > LOWCONST)
                n_roots = 0;

            else {
                float root = -c / b;
                n_roots = 1;
            }           
        }

        else    //введённое квадратное уравнение всё-таки действительно квадратное   
            n_roots = solve_quadratic_equation(a, b, c, root_1, root_2);    //количество корней
    
    return n_roots;
}


int solve_quadratic_equation(float a, float b, float c, float *root_1, float *root_2)
{
    float D = b*b - 4*a*c;
    if (D < 0)
        return 0;
    else if (D == 0) {
        *root_1 = -b / (2 * a);
        *root_2 = *root_1;
        return 1;
    }
    else {
        *root_1 = (-b - sqrt(D)) / (2 * a);
        *root_2 = (-b + sqrt(D)) / (2 * a);
        return 2;
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
    }
}

int menu()
{
    char enter_ch;
    

    while (1){
        printf("Enter Y if you want to continue or N to exit: ");
        scanf("%c", &enter_ch);

        if (enter_ch == 'Y' || enter_ch == 'y')
            return 1;
        else if (enter_ch == 'N' || enter_ch == 'n')
            return 0;
        else
            continue;
    }
}