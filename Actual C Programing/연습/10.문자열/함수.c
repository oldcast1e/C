#include  <stdio.h>
#include <string.h>
int main(){

    char str[15] = "Hello";
    char change[15] = "World";
    char name[10] = "Heonseong";


    int cnt = strcmp(str,change);
    cnt = strncmp(str,change,1);
    printf("%d",cnt);
    // printf("%s",str); 
    
    
}