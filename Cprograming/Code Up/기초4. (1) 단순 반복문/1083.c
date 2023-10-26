#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int i,n; scanf("%d",&n);
    for(i=1; i<=n; i++){
        if(i%3==0) printf("X "); //3또는 5의 배수인 경우 그 수 출력
        else printf("%d ",i);
    }
} 