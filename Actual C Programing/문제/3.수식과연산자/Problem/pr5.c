#include<stdio.h>
int main(){

    int n,m,k,l;
    scanf("%d",&n);
    k = (n/1000);//35
    m = (n/100)%10; // 3번째 자리
    k = m>=5?k+1:k;
    k *=1000;
    printf("%d",k);

    
    
}