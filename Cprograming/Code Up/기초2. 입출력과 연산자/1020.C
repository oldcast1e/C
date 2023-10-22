#include <stdio.h>
#include <string.h>

int main()
{   
    int cnt = 0;
    char arr[100],rst[100];
    scanf("%s",arr);
    for(int i=0;i<strlen(arr);i++){
        if(arr[i]!='-'){rst[cnt]=arr[i];cnt++;}
    }
    printf("%s",rst);
}

