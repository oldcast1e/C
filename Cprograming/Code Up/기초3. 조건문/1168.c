#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0,rst;
    float d,e,f;
    // scanf("%d",&a);
    scanf("%d %d",&a,&b);
    cnt = a/10000;// printf(">>%d\n",cnt);
    switch (b) //790101
    {
    case 1: //성별 정보는 1이면 1900년대 출생 남자, 
    case 2: //2이면 1900년대 출생 여자, 
        rst = 2012 - (1900 + cnt) + 1;
        printf("%d",rst);
        break;
    case 3://3이면 2000년대 출생 남자, 
    default://4이면 2000년대 출생 여자를 말한다.
        rst = 2012 - (2000 + cnt) + 1;
        printf("%d",rst);
        break;
    }
    // printf("%d",2012-a+1);
 
} 