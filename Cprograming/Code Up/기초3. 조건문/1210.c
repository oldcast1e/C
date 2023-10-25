#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c;
    float d,e,f,cnt;
    
    int cal[5]= {400,340,170,100,70};
    scanf("%d %d",&a,&b);
    int sum = cal[a-1]+ cal[b-1];
    if(sum > 500) printf("angry");
    else printf("no angry");
 
} 
/*
보림이는 먹고 싶은게 많았으나 엄마가 살이 찐다고 2가지만 골라서 먹으라고 했다.
그리고 두 메뉴의 칼로리 합이 500보다 크면 엄마가 화를 내고, 500이하면 화를 내지 않는다.
*/