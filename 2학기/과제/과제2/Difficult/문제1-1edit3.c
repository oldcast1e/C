#include  <stdio.h>
#include<string.h>
int main(){//메인함수

    char str[31],*pstr = str,tmp[30]={},*ptmp = tmp;
    char changeval,apt[10]={},*papt = apt;
    int N,num,key;

    for(int i=0;i<20;i++) *(apt+i) = ' ';
    for(int i=0;i<100;i++){
        scanf("%c",(pstr+i));
        if(*(pstr+i)=='\n') break;
    }
    scanf("%d",&N);
    for(int i=0;i<strlen(str);i++){
        if('A' <= *(pstr+i) &&  *(pstr+i)<= 'Z')*(pstr+i) += N;
        else if('a' <= *(pstr+i) &&  *(pstr+i)<= 'z')*(pstr+i) -= N;
        //////
        else if('0' <= *(pstr+i) &&  *(pstr+i)<= '9'){
            if('0' <= *(pstr+i+1) &&  *(pstr+i+1)<= '9') key = 1;
            else key = 0;

            strcpy(tmp,"");//tmp초기화
            
            if(key == 0){
                changeval = *(pstr+i);
                for(int k=0;k<N;k++) *(pstr+i+k) =  changeval + 16;//해당 숫자번째 대문자를 N번 반복저장
                for(int j=i+N;j<strlen(str);j++) *(pstr+j) =  *(tmp+j-i-N);
                
            } 
            else if(key == 1){
                num = 1;num *= (*(pstr+i)-48)*10;num += (*(pstr+i+1)-48);
                for(int k=0;k<N;k++) *(pstr+i+k) =  num + 64;

            } 
            // for(int j=i+N;j<strlen(str);j++) *(pstr+j) =  *(tmp+j-i-N);
            i += N - 1;
        }
        else *(pstr+i) = ' ';
    }
    printf("%s",str);
}

//CLikp5tGLE?Qej15J
//ENginEErING SchOOL
