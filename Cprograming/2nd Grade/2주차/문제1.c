#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int modulo(int n,int m){
    return (n%m);
}

/*
◦ modulo() 함수
- 인자: 정수 a, b - 반환값: a % b
*/
int main(){
    int n,m; scanf("%d %d",&n,&m);
    printf("%d",modulo(n,m));
   
    

    
} 
/*

*/