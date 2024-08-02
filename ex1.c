//ФУНКЦИЯ СИНУСА МЕТОДОМ РЯДОА ТЕЙЛОРА
#include <stdio.h>
#include <math.h>
int main() {
    double E, x, sinus, sk, i = 1;
    scanf("%lf %lf", &x, &E);
    int lmao;
    lmao = (int) (x/M_PI);
    x -= lmao*M_PI;
    sinus = x;
    sk = x;
    while (fabs(sk) >= E) {
        i += 2;
        sk *= -x*x/(i*i-i);
        sinus += sk;
    }
    printf("%lf\n", sinus);
    printf("%lf", sin(x));
}