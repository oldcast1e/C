#include <stdio.h>

int main() {
    int a = 0, b = 1, c, i;
    int fib[100] = {0, 1};
    for (i = 2; i < 100; i++) {
        c = a + b;
        fib[i] = c;
        a = b;
        b = c;
    }
    // 결과 출력
    for (i = 0; i < 100; i++) {
        printf("%d ", fib[i]);
    }

    printf("\n");

    return 0;
}