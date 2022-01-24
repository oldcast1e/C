#include  <stdio.h>
#include<string.h>
int main(){
    char str1[50],str2[50],rst[100];
    scanf("%s",str1);scanf("%s",str2);
    if(strcmp(str1,str2)>0){
        strcat(rst,str1);
        strcat(rst,str2);
    } 
    else{
        strcat(rst,str2);
        strcat(rst,str1);
    }
    printf("%s",rst);

}
//공백을 포함하지 않는 문자열 2개를 입력받고
//두 문자열의 크기를 비교한 후 , 크기가 큰 문자열 뒤에 크기가 작은 문자열이 오도록 만들고 출력하는 프로그램