#include <stdio.h>
int myabs(int a){
    return (a<0?a*=-1:a);
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", myabs(a));
}