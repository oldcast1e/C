#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
[ 문제 2 ] 양의 정수를 입력 받아, 
각 자리의 수를 높은 자릿수부터 차례로 
출력하는 프로그램을 작성하시오.
 */
void save(int num[],int n){
    
    if( n> 0) {
        int tmp = n,len=0;
        while(tmp > 0){len ++; tmp/=10;}
        // printf("len = %d\n",len);
        num[len - 1] = n % 10;
        // printf("%d\n",num[len - 1]);
        n /= 10;
        return save(num,n);
    }
}

int main(){
    int n; scanf("%d",&n);
    int num[1000];
    save(num,n);
    int tmp = n,len=0;
    while(tmp > 0){len ++; tmp/=10;}
    for(int i=len-1;i>=0;i--)printf("%d\n",num[i]);

} 
