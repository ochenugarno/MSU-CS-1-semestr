//метод разделения отрезка пополам
#include <stdio.h>
#include <math.h>
int main() {
    double E, a, b, left, right, x;
    int N, naydennye = 0;
    scanf("%lf %d", &E, &N);
    a = M_PI/2 + E;
    b = 3*M_PI/2 - E;
    while (naydennye < N) {
        left = a;
        right = b;
        while (fabs(right - left) >= E/2) {
            x = (left + right)/2;
            if ((tan(left) - left) * (tan(x) - x) >= 0) {
                left = x;
            } else {
                right = x;
            }
        }
        printf("%lf %lf\n", (left + right)/2, tan((left + right)/2));
        naydennye++;
        a = b + 2*E;
        b += M_PI;
    }
}
