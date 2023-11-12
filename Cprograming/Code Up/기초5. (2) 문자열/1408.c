#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    char arr[20],rst1[20];
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        rst1[i] = arr[i] + 2; 
    }
    for(int i=0;i<(int)strlen(arr);i++)printf("%c",rst1[i]);
    printf("\n");
    for(int i=0;i<(int)strlen(arr);i++)
        printf("%c",(arr[i]*7)%80 + 48);

} 
/*
인터넷 서비스들은 대부분 아이디와 패스워드(password)를 이용한다.
이때 사용되는 패스워드는 여러 가지 방법으로 암호화되어 저장된다.

[어떤 인터넷 서비스의 2가지 암호화 방법]

- 입력받은 문자의 ASCII 코드값 + 2
- (입력받은 문자의 ASCII 코드값 * 7) % 80 + 48

사용자의 패스워드를 2가지 방법으로 암호화한 결과를 출력하는 프로그램을 작성하시오.

TEST

VGUV
L3EL
*/