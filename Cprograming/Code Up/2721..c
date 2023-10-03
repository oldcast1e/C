/*
영어 소문자로 구성된 단어 S1, S2, S3가 있을때,
S1의 마지막 문자가 S2의 첫 글자와 같고,
S2의 마지막 글자가 S3의 첫 글자와 같고,
S3의 마지막 글자가 S1의 첫 글자와 같으면 순환 문자열이라고 한다.

예를 들어 turtle error robot 인 경우 순환 문자열이다.

세 단어가 주어졌을 때 순환 문자열이면 good을 출력, 아니면 bad를 출력하시오.

영어 소문자로 구성된 단어 S1, S2, S3가 각 줄에 한개씩 입력된다.(각 문자열에 공백은 없으며 길이는 2글자 이상 20글자 이하이다.)
순환 문자열이면 good을 출력, 아니면 bad를 출력하시오.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char wrd1[20],wrd2[20],wrd3[20];
    scanf("%s",wrd1);scanf("%s",wrd3);scanf("%s",wrd3);

    char fir_wrd1,lst_wrd1; int leng_wrd1 = strlen(wrd1);
    char fir_wrd2,lst_wrd2; int leng_wrd2 = strlen(wrd2);
    char fir_wrd3,lst_wrd3; int leng_wrd3 = strlen(wrd3);

    fir_wrd1 = wrd1[0]; lst_wrd1 = wrd1[leng_wrd1-1];
    printf("fir = %c | last = %c", fir_wrd1,lst_wrd1);

}