#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define z 0.0
#define c 5.0

void Hovel(double A, double Err, int n)
{
    printf("A = %lf\n", A);
    printf("fault = %lf\n", Err);
    printf("Count of steps = %d\n", n);
    printf("ALL OK\n\n");
}
double Calculate(double x)//Integral calculation function
{
    return (1 / (2 * x + 1.5));
}
double Pryamokutnyk(int n)//The function of calculating the integral by the method of rectangles
{
    double h, A, x;
    h = (c - z) / n;
    for (x = z; x <= c; x = x + h)
    {
        A = A + Calculate(x);
    }
    A = A * h;
    return A;
}
double Trapecia(int n)//Trapezoidal integral calculation function
{
    double h, A = 0, x;
    h = (c - z) / n;
    A = Calculate(c) + Calculate(z);
    for (x = z; x <= c; x = x + h)
    {
        A = A + Calculate(x);
    }
    A = A * h;
    return A;
}
double Simpson(int n)//The function of calculating the integral by the Simpson method
{
    double h, A = 0, M = 0;
    int i = 0;
    h = ((c - z) / n);
    for (i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            A = A + Calculate(z + h * i);
        }
        if (i % 2 == 0)
        {
            M = M + Calculate(z + h * i);
        }
    }
    A = ((c - z) / (3 * n)) * (Calculate(z) + 4 * A + 2 * M + Calculate(c));
    return A;
}
int main()
{
    int var, n, i, j = 1;
    double h, d, x, A = 0.0, M = 0.0, L1, L2;
    while (1)             // infinite cycle
    {
        printf("Choise method: \n");
        printf("1 - Method of rectangles\n2 - Method of trapezoidal\n3 - Simpson method\n4 - Usual method\n5 - Demo version(y = sqrt(x))\n");
        scanf("%d", &var);
        switch (var)
        {
        case 1://Rectangles
            printf("Count of steps: \n");
            scanf("%d", &n);
            for (j; j <= 2; j++)
            {
                if (j == 1)
                {
                    A = Pryamokutnyk(n);
                    n = n + 2;
                }
                M = Pryamokutnyk(n);
                if (fabs(A - M) > 0.00001 && fabs(A - M) < 0.001)//whether the error satisfies the answer
                {
                    M = fabs(A - M);
                    Hovel(A, M, n);
                    break;
                }
                else
                {
                    j = 0;//start from the beginning if the error does not satisfy the answer
                }
            }
            break;
        case 2://Trapezoidal
            printf("Count of steps: \n");
            scanf("%d", &n);
            for (j; j <= 2; j++)
            {
                if (j == 1)
                {
                    A = Trapecia(n);
                    n = n + 2;
                }
                M = Trapecia(n);
                if (fabs(A - M) > 0.00001 && fabs(A - M) < 0.001)
                {
                    M = fabs(A - M);
                    Hovel(A, M, n);
                    break;
                }
                else
                {
                    j = 0;
                }
            }
            break;
        case 3://Simpson
            do
            {
                printf("This method must have an even number of intervals \n");
                printf("Count of steps: \n");
                scanf("%d", &n);
            } while (n % 2 != 0);
            for (j; j <= 2; j++)
            {
                if (j == 1)
                {
                    A = Simpson(n);
                    n = n + 2;
                }
                M = Simpson(n);
                if (fabs(A - M) > 0.00001 && fabs(A - M) < 0.001)
                {
                    M = fabs(A - M);
                    Hovel(A, M, n);
                    break;
                }
                else
                {
                    j = 0;
                }
            }
            break;
        case 4://Usual integral
            A = (0.5 * (log(fabs(2 * z + 1.5))));
            M = (0.5 * (log(fabs(2 * c + 1.5))));
            A = M - A;
            printf("A : %lf\n\n", A);
            break;
        case 5:
            //My function: y = sqrt(x)
            printf("My integral (0->5) y = sqrt \n");
            printf("Count of steps: \n");
            scanf("%d", &n);
            printf("Calculator answer : 7.45356\n");//Calculator
            //1
            h = ((c - z) / n);
            for (x = z; x <= c; x = x + h)
            {
                A = A + sqrt(x);
            }
            A = A * h;
            printf("Method of rectangles : %lf\n", A);
            //2
            h = (c - z) / n;
            A = sqrt(z) + sqrt(c);
            for (x = z; x <= c; x = x + h)
            {
                A = A + sqrt(x);
            }
            A = A * h;
            printf("Method of trapezoidal : %lf\n", A);
            //3
            h = ((c - z) / n);
            for (i = 0; i <= n; i++)
            {
                if (i % 2 != 0)
                {
                    A = A + (sqrt(z + h * i));
                }
                if (i % 2 == 0)
                {
                    M = M + sqrt(z + h * i);
                }
            }
            A = ((c - z) / (3 * n)) * (sqrt(z) + 4 * A + 2 * M + sqrt(c));
            printf("Simpson method : %lf\n\n", A);
            break;
        default:
            printf("No one variant\n");//If the user hasn't choosen a variant
            break;
        }
    }
    return 0;
}