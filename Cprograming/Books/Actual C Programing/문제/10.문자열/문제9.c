#include  <stdio.h>
#include<string.h>

int check(char *strdir){
    int rst=0,len=0,cnt=0,icnt;
    char frt[16],bck[16];
    while(1){
        if(*(strdir+len)=='\0') break;
        len++;
    }
    for(int i=0;i<len/2;i++) frt[i]= *(strdir+i);//2=>0~1
    icnt=(len%2==0?len/2-1:len/2);
    for(int i=len-1;i>icnt;i--){
        bck[cnt]= *(strdir+i); //4~3
        cnt++;
    } 
    // printf("%s\n",frt);
    // printf("%s\n",bck);
    rst = (strcmp(frt,bck)==0?1:0);
    
    return rst;
}
int main(){
    char str[31],*pstr = str;
    scanf("%s",str);
    printf("%d %d",(int)strlen(str),check(pstr));



}
//공백을 제외한 문자열을 입력받아
//입력받은 문자열의 회문 여부를 판단하는 프로그램
//출력: 문자열의 크기. 회문 여부(맞으면 1아니면 0)

//입력받은 문자열의 길이(n)가 홀수인경우 ex)heleh 5/2=2 ->앞에서부터 n/2개 뒤에서부터 n/2개
//입력받은 문자열의 길이(n)가 짝수인경우 ex)worrow