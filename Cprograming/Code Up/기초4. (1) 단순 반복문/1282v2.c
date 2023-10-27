#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    long int n,k=1,t,rep=1;
    scanf("%ld",&n);
    for(long int i=n;i>=1;i--){ // 입력받은 n부터 1까지 반복 (A) = i
        if(i % 100 == 0)printf("실행 중..\n");
        for(long int j=1;j<=i/2;j++){//1부터 i까지 반복
        //이때 해당 반복을 하는 이유는 A의 값(제곱수)는 1씩 떨어지고,
        //1부터 어떤 수가 제곱했을 때 A의 값(i)이 되는지 찾아야하기 때문이다.
            if(j*j == i){
                printf(">> i = %ld | j*j = %ld | j = %ld\n",i,j*j,j);
                printf("%ld %ld",n-i,j); rep= 0;
                break;
            }
        }if(rep==0)break;
    }
} 