#include <stdio.h>
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
int mymax(int a, int b){
    return(a>b?a:b);
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", mymax(a, b));
}