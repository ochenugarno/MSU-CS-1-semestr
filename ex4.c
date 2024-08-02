//ИНТЕГРАЛ МЕТОДОМ ПРЯМОУГОЛЬНИКОВ
#include <stdio.h>
#include <math.h>
int main(){
    double a, b, E, dx, integral1, integral2;
    scanf("%lf %lf %lf", &a, &b, &E);
    dx = b-a;
    integral1 = 0;
    integral2 = dx*b*b;
    int i, n = 1;
    while (fabs(integral1 - integral2) >= E) {
        dx /= 2;
        n <<= 1;
        integral1 = integral2;
        integral2 = 0;
        for (i = 1; i < n+1; i++) {
            integral2 += dx*(a+i*dx)*(a+i*dx);
        }
    }
    printf("%lf\n", integral2);
    printf("%lf\n", (b*b*b-a*a*a)/3);
    printf("%d", n);
}
