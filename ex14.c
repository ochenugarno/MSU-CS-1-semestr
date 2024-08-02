#include <stdio.h>
int main() {
    FILE *f;
    f = fopen("a.txt", "r");
    int a, ap = 0;
    a = fgetc(f);
    while (a != EOF) {
        if ( a == 'f' && (ap == ' ' || ap == '\n' || !ap)) {
            ap = a, a = fgetc(f);
            if (a == 'i') {
                ap = a, a = fgetc(f);
                if (a == 'l') {
                    ap = a, a = fgetc(f);
                    if (a == 'e') {
                        ap = a, a = fgetc(f);
                        if (a == ' ' || a == '\n' || a == EOF) {
                            printf("FILE");
                        } else {
                            printf("file");
                        }
                    } else {
                        printf("fil");
                    }
                } else {
                    printf("fi");
                }
            } else {
                printf("f");
            }
        } else {
            printf("%c", a);
            ap = a, a = fgetc(f);
        }
    }
}
