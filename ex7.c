#include <stdio.h>
#include <math.h>
int main() {
    double h = cos(M_PI/4) + 0.001, x0 = 1, t0 = 0, x1, t1, er, xist;
    t1 = t0 + h;
    x1 = x0 - h*2*x0*x0*t0;
    //x1 = x0 - h*(x0*x0*t0 + x1*x1*t1);
    //printf("%lf %lf\n", t0, x0);
    //printf("%lf %lf\n", t1, x1);
    xist = 1/(1 + t1*t1);
    er = fabs(xist - x1);
    printf("%lf %lf\n", t1, er);
    int i;
    for (i = 0; i < 25; i++) {
        t0 = t1;
        x0 = x1;
        t1 = t0 + h;
        x1 = x0 - h*2*x0*x0*t0;
        //x1 = x0 - h*(x0*x0*t0 + x1*x1*t1);
        //printf("%lf %lf\n", t1, x1);
        xist = 1/(1 + t1*t1);
        er = fabs(xist - x1);
        printf("%lf %lf\n", t1, er);
    }
}
