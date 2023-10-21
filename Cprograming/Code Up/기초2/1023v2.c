#include <stdio.h>
#include <string.h>

int main()
{   
   char arr[50];
   scanf("%s",arr);
   for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i]=='.')printf("\n");
        else printf("%c",arr[i]);
   }
}

