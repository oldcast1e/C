#include <stdio.h>
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
void myswap(int *a, int *b){
    if(*a>*b){
        int tmp; tmp = *a;
        *a = *b; *b = tmp;
    }
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    myswap(&a, &b);
    printf("%d %d", a, b);
} 