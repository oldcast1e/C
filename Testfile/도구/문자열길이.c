#include<stdio.h>
#include<string.h>
int main(){
    // int M,K1,K2,result;
    // int len;
    char str[100] = {0,},tmp[10]={0},*pstr= str;
    int cnt=0;
    // scanf("%d",&M);
    // getchar();
    // for(int i=0;i<M;i++){
    //     gets(str);
    //     printf("%d\n",(int)strlen(str));
    //     printf("%d\n",(int)strlen(str+1));
    // }
    
    for(int i=0;i<100;i++){
        
        scanf("%c",(pstr+i));
        if(*(pstr+i)=='\n') break;
        cnt++;
    }
    printf("%d",cnt);
    //ENginEErING SchOOL
    //CLikp5tGLE?Qej15J
}