#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int card_cvt(unsigned int x, int n, char arr[]){
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digit = 0;
    if(x == 0) arr[digit++] = '0';
    else{
        while(x){
            arr[digit++] = dchar[x%n];
            // printf(">>%c",arr[digit-1]);
            x/=n;
        }
    }
    return digit;
}


int main(){
    int unsigned num,cd,tmp;//cd: 기수
    char arr[512];
    while(1){
        printf("10진수를 기수 변환합니다.\n");
        printf("변환하는 음이 아닌 정수: "); scanf("%d",&num);
        printf("어떤 진수로 변환할까요?(2-36):") ;scanf("%d",&cd);
        int digit = card_cvt(num,cd,arr);

        for(int i=digit-1;i>=0;i--)printf("%c",arr[i]);
        printf("\n다시 실행하기(1 - 예/0 - 아니오): "); scanf("%d",&tmp);
        if(tmp == 0) break;
    }
    

    
} 
/*

*/