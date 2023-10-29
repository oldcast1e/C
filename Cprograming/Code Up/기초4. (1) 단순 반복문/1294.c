#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[201];
    fgets(arr, 201, stdin);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]=='\n') break;

        if(arr[i] == ' ') continue;
        else if(arr[i]+3 > 'z') arr[i] = 'c' - ('z' - arr[i]);
        else arr[i] += 3;
    }
    printf("%s",arr);
} 
/*
시저 암호는 알파벳을 3글자씩 밀려서 쓰면서 문장을 만들었다. 
실제 시저는 부하인 브루투스에게 암살되기 전에 키케로에게 다음과 같은 암호문을 보냈다고 한다.

a b c
x y z
*/