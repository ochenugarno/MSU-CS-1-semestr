#include <stdio.h>
#include <math.h>
int main() {
    double h;
    scanf("%lf", &h);
    double xi = 1000000, xi_do = xi - h, xi_posle = xi + h, fi = sin(xi), fi_do = sin(xi_do), fi_posle = sin(xi_posle), count = 1000000;
    FILE *ex13;
    ex13 = fopen("ex13.txt", "w");
    fprintf(ex13, "%lf   %lf   %lf   %lf\n", xi, (fi_posle - fi)/h, (fi_posle - fi_do)*0.5/h, (fi_posle + fi_do - 2*fi)/(h*h));
    int i;
    while (xi < 1000004) {
        xi += h;
        xi_do += h;
        xi_posle += h;
        fi = sin(xi);
        fi_do = sin(xi_do);
        fi_posle = sin(xi_posle);
        if (xi > count) {
            fprintf(ex13, "%lf   %lf   %lf   %lf\n", xi, (fi_posle - fi) / h, (fi_posle - fi_do) * 0.5 / h,
                    (fi_posle + fi_do - 2 * fi) / (h * h));
            count += 0.01;
        }
    }
}
