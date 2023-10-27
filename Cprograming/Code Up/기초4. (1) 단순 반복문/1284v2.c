#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,cnt=0,key=0;
    float n1,n2;
    
    scanf("%d",&a); //printf("인수를 출력합니다.\n");
    for(int i=1;i<=a;i++){
        if(a%i==0){
            // printf("인수>>%d\n",i); //1 997
            cnt = 0;
            for(int j=1;j<=i;j++){ //인수 중에 소수인지 확인
                if(i%j == 0) cnt ++;
            }if(i==2)cnt =0;
            if(cnt == 2 && i!=1 && i!=a){//인수가 2가 아니고 1이나  입력된 숫자가 아닌 소수인 경우
                key=1;
                printf("%d %d",i,a/i);
                break;
            }
 
        }
    }
    if(key==0)printf("wrong number");
    
 
} 