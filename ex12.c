//метод разделения + метод касательных
#include <stdio.h>
#include <math.h>
int main() {
    double E, a, b, left, right, x;
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
        while (fabs(tan(right) - right) > E) {
            right -= (tan(right) - right)/(tan(right) * tan(right));
        }
        printf("%lf %lf\n", right, tan(right));
        naydennye++;
        a = b + 2*E;
        b += M_PI;
    }
}

