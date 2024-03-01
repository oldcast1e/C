#include <stdio.h>
#include <string.h>
//공백을 포함한 문장 출력: fgests함수 이용
//fgets( ) 를 사용하면 공백문자가 포함되어잇는 문장을 입력받아 저장할 수 있다.
int main()
{   
    int cnt = 0;
    char arr[100],rst[100];
    fgets(arr, 2000, stdin);
    printf("%s",arr
    );
}

