#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int N;
    for (N = 16; N < 10000000000000000000; N *= 2) {
        int mass[N], i, j;
        srand(time(0));

        for (i = 0; i < N; i++) {
            mass[i] = rand() % 90 + 10;
            //printf("%d ", mass[i]);
        }
        //printf("\n"); //вывод введенного массива
        clock_t begin = clock();
        int cur = 0, cut = 1, count;
        while (cut < N) {
            int n1[cut], n2[cut];
            while (cur < N) {
                count = 0;
                for (i = cur; i < cur + cut; i++) n1[count++] = mass[i];
                count = 0;
                for (i = cur + cut; i < cur + (cut << 1); i++) n2[count++] = mass[i];
                //for (int k = 0; k < cut ;k++) //printf("%d ", n1[k]);
                //printf("\n");
                //for (int k = 0; k < cut; k++) //printf("%d ", n2[k]);;
                //printf("\n");
                i = 0, j = 0;
                while (i + j < cut << 1) {
                    if (i != cut && (j == cut || n1[i] < n2[j])) {
                        mass[cur + i + j] = n1[i];
                        i += 1;
                    } else {
                        mass[cur + i + j] = n2[j];
                        j += 1;
                    }
                }
                cur += cut << 1;

                //for (int k = 0; k < N; k++) printf("%d ", mass[k]);
                //printf("\n\n");
            }
            cur = 0;
            cut <<= 1;
        }
        clock_t end = clock();
        //for (i = 0; i < N; i++) printf("%d ", mass[i]); //вывод отсортированного массива
        printf("%d %lf\n", N, (double) (end - begin) / CLOCKS_PER_SEC);
    }
}

