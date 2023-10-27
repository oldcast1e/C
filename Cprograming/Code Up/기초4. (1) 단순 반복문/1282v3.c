#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,k=1,t,rep=1;
    scanf("%d",&n);
    for(int i=n;i>=1;i--){ // 입력받은 n부터 1까지 반복 (A) = i
        if(i % 100 == 0)printf("실행 중..\n");
        for(int j=1;j<=i;j++){//1부터 i까지 반복
        //이때 해당 반복을 하는 이유는 A의 값(제곱수)는 1씩 떨어지고,
        //1부터 어떤 수가 제곱했을 때 A의 값(i)이 되는지 찾아야하기 때문이다.
            if(pow(j,2)==i){
                printf(">> i = %d | j*j = %d | j = %d\n",i,j*j,j);
                printf("%d %d",n-i,j); rep= 0;
                break;
            }
        }if(rep==0)break;
    }
} 