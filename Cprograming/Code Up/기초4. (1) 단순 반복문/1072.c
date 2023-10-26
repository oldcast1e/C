#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
     int n, m;
    scanf("%d", &n);
    reget: //레이블은 콜론( : ) 으로 끝난다.
    scanf("%d", &m);
    
    if(n-- != 0){ printf("%d\n", m);goto reget;} //reget:으로 이동, n의 값 1만큼 감소
 
} 