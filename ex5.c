//ИНТЕГРАЛ МЕТОДОМ ТРАПЕЦИИ
#include <stdio.h>
#include <math.h>
int main() {
    double a, b, E, dx, integral1, integral2;
    scanf("%lf %lf %lf", &a, &b, &E);
    dx = b - a;
    integral1 = 0;
    integral2 = dx/2*(b*b+a*a);
    int i, n = 0;
    while (fabs(integral1 - integral2) >= E) {
        dx /= 2;
        n++;
        integral1 = integral2;
        integral2 = 0;
        for (i = 1; i < (b - a) / dx + 1; i++) {
            integral2 += dx/2*((a+i*dx)*(a+i*dx)+(a+(i+1)*dx)*(a+(i+1)*dx));
        }
    }
    printf("%lf\n", integral2);
    printf("%lf\n", (b * b * b - a * a * a) / 3);
    printf("%d", n);
}