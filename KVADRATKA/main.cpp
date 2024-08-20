#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const float LOWCONST = 0.0001;

int solve_quadratic_equation(float a, float b, float c, float *root1, float *root2);

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;

    float root1 = 0;
    float root2 = 0;
    
    printf("\nThis program solves a quadratic equation. \nEnter three coefficients (a b c) for the solution or any letter to exit.\n");

    while (scanf("%f %f %f", &a, &b, &c) == 3)
    {   
        char curr_ch = 0;
        while ((curr_ch = getchar()) != '\n')     //пропускаем остальной ввод, если он был
            continue;

        if (fabs(a) < LOWCONST)
        {
            if (fabs(b) < LOWCONST && fabs(c) < LOWCONST)
                printf("All coefficients are zero. Root is any number.\n");

            else if (fabs(b) < LOWCONST && fabs(c) > LOWCONST)
                printf("The equation has no roots! \n");

            else {
                float root = -c / b;
                printf("The introduced equation is linear. It has a single root = %.2f", root);
            }
            
        }

        else    //введённое квадратное уравнение всё-таки действительно квадратное
        {     
            int num = solve_quadratic_equation(a, b, c, &root1, &root2);    //количество корней
            if (num == 0)
                printf("The equation has no roots! (D<0) \n");
            else if (num == 1)
                printf("(D = 0) The equation has a single root = %.2f \n", root1);
            else
                printf("The introduced equation is solver. It has two roots: %.2f, %.2f \n", root1, root2);
        }   
    }

    printf("The program is completed\n");
}

int solve_quadratic_equation(float a, float b, float c, float *root1, float *root2)
{
    float D = b*b - 4*a*c;
    if (D < 0)
        return 0;
    else if (D == 0) {
        *root1 = -b / (2 * a);
        *root2 = *root1;
        return 1;
    }
    else {
        *root1 = (-b - sqrt(D)) / (2 * a);
        *root2 = (-b + sqrt(D)) / (2 * a);
        return 2;
    }
}