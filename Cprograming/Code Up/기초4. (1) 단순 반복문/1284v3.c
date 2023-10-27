#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0,fac=0;
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        if(a%i==0){
            fac ++;
            cnt = 0;
            for(int j=1;j<=i;j++){ //인수 중에 소수인지 확인
                if(i%j == 0) cnt ++;
            } 
            if(cnt == 2)printf("->소수: %d\n",i);
        }
    }
    printf("인수의 개수: %d\n",fac);
    if(fac == 4){
        for(int i=(a-1);i>=1;i--){
            if(a%i==0){ 
                printf("%d %d",i,a/i);
                break;
            }
        }
    }
} 

/*
입력:
28
정답:
wrong number
-------------
입력:
2
정답:
wrong number
------------
997
wrong number

*/