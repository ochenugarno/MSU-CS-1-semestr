//РЕКУРСИЯ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void vvod(int* mass, int i, int n) {
    if (i < n) {
        mass[i] = rand()%90 + 10;
        vvod(mass,i + 1, n);
    }
}
void vyvod(int* mass, int i, int n) {
    if (i < n) {
        printf("%d", mass[i]);
        printf(" ");
        vyvod(mass,i + 1, n);
    }
}
int max(int* mass, int i, int n, int CHAD) {
    if (i <= n) {
        if (mass[i] > CHAD) {
            CHAD = mass[i];
        }
        return max(mass, i + 1, n, CHAD);
    }
    return CHAD;
}
int step(int a, int s, int st) {
    if (a > 1) {
        st *= 2;
        return step(a/2, s + st, st);
    }
    return s;
}
void anal(int* amass, int* bmass, int i, int stepen, int por_chast, int len, int n) {
    if (i < len) {
        bmass[i] = max(amass, por_chast*n/stepen, por_chast*n/stepen-1 + n/stepen, amass[por_chast*n/stepen]);
        if (por_chast + 1 == stepen) {
            anal(amass, bmass, i + 1, stepen*2, 0, len, n);
        } else {
            anal(amass, bmass, i + 1, stepen, por_chast+1, len, n);
        }
    }
}
int main() {
    srand(time(0));
    int N;
    scanf("%d", &N);
    int length = step(N, 1, 1);
    int *a = (int*) malloc(N * sizeof(int));
    int *b = (int*) malloc(length * sizeof(int));
    vvod(a,0,N);
    vyvod(a,0,N);
    printf("\n");
    anal(a, b, 0, 1, 0, length, N);
    vyvod(b, 0, length);
    free(a);
    free(b);
}
