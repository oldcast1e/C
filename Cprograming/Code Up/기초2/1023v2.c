#include <stdio.h>
#include <string.h>

int main()
{   
    char arr[100];
    int cnt = 0;
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]=='.'){printf("%d",cnt/10); cnt= 0;}
        else {cnt += arr[i]-'0'; cnt *= 10;}
    }printf("\n%d",cnt/10);

   
}

