#include <stdio.h>
#include <string.h>

int main()
{   
    char arr[100];
    int cnt = 0;
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(i==0) printf("%d\n",arr[i]-'0');
        else if(arr[i]!='.'){
            cnt += (arr[i])-'0';
            cnt*= 10;
        }//printf(">>%d\n",cnt);
    }
    cnt/=10;
    printf("%d",cnt);
}

