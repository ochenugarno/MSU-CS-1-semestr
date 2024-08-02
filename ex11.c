//метод разделения отрезка пополам + метод хорд
#include <stdio.h>
#include <math.h>
int main() {
    double E, a, b, left, right, x, B;
    int N, naydennye = 0;
    scanf("%lf %d", &E, &N);
    a = M_PI/2 + E;
    b = 3*M_PI/2 - E;
    int i;
    while (naydennye < N) {
        left = a;
        right = b;
        for (i = 1; i < 11; i++) {
            x = (left + right)/2;
            if ((tan(left) - left) * (tan(x) - x) >= 0) {
                left = x;
            } else {
                right = x;
            }
        }
        B = right;
        x = left;
        while (fabs(tan(x) - x) > E) {
            x = ((tan(B) - B)*x - (tan(x) - x)*B)/(tan(B) - B - tan(x) + x);
        }
        printf("%lf %lf\n", x, tan(x));
        naydennye++;
        a = b + 2*E;
        b += M_PI;
    }
}
