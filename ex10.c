//ИНТЕГРАЛ МЕТОДОМ МОНТЕ-КАРЛО
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    double a, b, x, y, ymax, k = 0, n = 0;
    scanf("%lf %lf", &a, &b);
    srand(time(0));
    ymax = a*a > b*b ? a*a : b*b;
    int i;
    for (i = 1; i < 10001; i++) {
        n++;
        x = (double) rand()/RAND_MAX*(b-a)+a;
        y = (double) rand()/RAND_MAX*ymax;
        k += (y<=x*x);
    }
    printf("%lf", k*ymax*(b-a)/n);
}