#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* 정답 */
void ABC(char *arr, int len){
    char tmp = arr[0];
    for(int i=1;i<len;i++){arr[i-1] = arr[i];}
    arr[len-1] = tmp;
}

//입력 받는 문자열 길이는 최대 100 이다.
int main(){
    //순환문이용

    char arr[100]; scanf("%s",arr);
    int len = (int)strlen(arr);
    printf("%s\n",arr); ABC(arr,len);
    for(int i=1;i<len-1;i++){
        ABC(arr,len);
        printf("%s\n",arr);
    }
} 
//abcde
