#include  <stdio.h>
#include<string.h>
int main(){
    char str1[50],str2[50],rst[100];//크기 50의 두개의 배열을 선언하고 결과값을 저장할 배열 선언
    scanf("%s",str1);scanf("%s",str2);//두 배열에 문자열을 입력받고
    if(strcmp(str1,str2)>0){//사전적 순서비교  = 배열2이 먼저인경우
        strcat(rst,str1);//결과값에 배열1저장
        strcat(rst,str2);//결과값에 배열2저장
    } 
    else{//사전적 순서비교  = 배열1이 먼저인경우
        strcat(rst,str2);//결과값에 배열2저장
        strcat(rst,str1);//결과값에 배열1저장
    }
    printf("%s",rst);//결과출력

}
//공백을 포함하지 않는 문자열 2개를 입력받고
//두 문자열의 크기를 비교한 후 , 크기가 큰 문자열 뒤에 크기가 작은 문자열이 오도록 만들고 출력하는 프로그램