#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        if(i%3==0)
            continue; //짝수라면? 아래 부분은 건너뛰고! 계속~
        printf("%d ", i); //결국 짝수가 아닐 때에만 출력된다.
    }
    
} 