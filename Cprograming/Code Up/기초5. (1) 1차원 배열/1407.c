#include <stdio.h>
#include <string.h>

int main()
{   
    int cnt = 0;
    char arr[100];
    fgets(arr, 101, stdin);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]!=' ')printf("%c",arr[i]);
    }
}

