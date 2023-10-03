#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char num1[101],num2[101];
    scanf("%s",num1); scanf("%s",num2);
    if((int)strlen(num1) == (int)strlen(num2)){
      //입력된 숫자의 길이만큼 서로의 값 비교
      int len = (int)strlen(num1); 
      for(int i=0;i<len;i++){
        if(num1[i] > num2[i]){printf("%s %s",num2,num1); break;}
        else if if(num1[i] < num2[i]){printf("%s %s",num1,num2); break;}
      }
    }
    else if((int)strlen(num1) < (int)strlen(num2))printf("%s %s",num1,num2);
    else printf("%s %s",num2,num1);
    //- 문자열 A가 문자열 B보다 작은 경우 -값 반환

}