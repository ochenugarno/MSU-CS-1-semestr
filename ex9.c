#include <stdio.h>
#include <math.h>
int main() {
    int r;//1 - правая, 2 - центральная 3 - вторая производная
    double h;
    scanf("%lf %d", &h, &r);
    double x0 = 0, y0 = sin(x0), y1, x1, x2, y2;
    int i;
    if (r == 1) {
        for (i = 0; i < 1000; i++) {
            x0 += h;
            y1 = sin(x0);
            printf("%lf %lf\n", x0, (y1 - y0) / h);
            y0 = y1;
        }
    }
    if (r == 2) {
        for (i = 0; i < 1000; i++) {
            x0 += h;
            x1 = x0 - h;
            x2 = x0 + h;
            y1 = sin(x1);
            y2 = sin(x2);
            printf("%lf %lf\n", x0, (y2 - y1)*0.5/h);
        }
    }
    if (r == 3) {
        for (i = 0; i < 1000; i++) {
            x0 += h;
            y0 = sin(x0);
            x1 = x0 - h;
            x2 = x0 + h;
            y1 = sin(x1);
            y2 = sin(x2);
            printf("%lf %lf\n", x0, (y2 + y1 - 2*y0)/(h*h));
        }
    }
}
