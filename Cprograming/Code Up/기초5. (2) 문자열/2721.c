#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    char arr_a[20],arr_b[20],arr_c[20];
    float n1,n2;
    //fgets(arr, 101, stdin);
    // scanf("%d",&a);
    scanf("%s",arr_a);scanf("%s",arr_b);scanf("%s",arr_c);
    if(arr_a[(int)strlen(arr_a)-1] == arr_b[0] &&
        arr_b[(int)strlen(arr_b)-1] == arr_c[0] &&
         arr_c[(int)strlen(arr_c)-1] == arr_a[0]
        ) printf("good");
    else printf("bad");
    // for(int i=0;i<(int)strlen(arr);i++)
    //for(int i=0;i<cnt;i++)
    // scanf("%d %d %d %d",&a,&b,&c,&d);
    
    // printf("%d",'b'-'a');
    
} 
/*
영어 소문자로 구성된 단어 S1, S2, S3가 있을때,

S1의 마지막 문자가 S2의 첫 글자와 같고,
S2의 마지막 글자가 S3의 첫 글자와 같고,
S3의 마지막 글자가 S1의 첫 글자와 같으면 순환 문자열이라고 한다.

예를 들어 turtle error robot 인 경우 순환 문자열이다.

세 단어가 주어졌을 때 순환 문자열이면 good을 출력, 아니면 bad를 출력하시오.

turtle
error
robot

good
*/