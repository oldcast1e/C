#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*소수의 나열 - 알고리즘1*/
int main(){
    int n,i,cnt=0;
    for(n=2;n<=1000;n++){
        for(i=2;i<n;i++){
            cnt ++;
            if(n%i == 0) break;
        }
        if(n == i) printf("%d\n",n);
    }
    printf("나눗셈을 시행한 횟수: %d",cnt);
}