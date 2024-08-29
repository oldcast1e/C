#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
[ 문제 2 ] 양의 정수를 입력 받아, 
각 자리의 수를 높은 자릿수부터 차례로 
출력하는 프로그램을 작성하시오.
 */
// void print(int n){
//     int tmp = n,len = 0,cal = 1;
//     while(tmp > 0){len ++; tmp/=10;cal *= 10;} cal/=10;
//     // printf("len = %d\n",len);
//     // printf("cal = %d\n",cal);
//     // printf("n = %d\n",n - n/cal*cal);

//     if(n > 0){
//         printf("%d\n",n/cal);
//         n = n - n/cal*cal;
//         print(n);
//     }
// }
int num[100]={0};
void save(int n){
    int tmp = n,len=0;
    while(tmp > 0){len ++;tmp/=10;}
    // printf("%d\n",n%10);
    num[len-1] = n%10;
    // printf("%d\n",num[len-1]);
    // printf("len = %d\n",len);
    n /= 10;
    if(n > 0) save(n);
}

int main(){
    int n; scanf("%d",&n);
    int tmp = n,len=0;
    save(n);
    for(int i=0;i<len;i++) printf("%d ",num[i]);

} 
