#include  <stdio.h>
#include <string.h>
int main(){
    char arr[40] = "Sejong Univ";
    char carr[40] = "Ime 21011898";
    strcpy(arr,carr);
    printf("%s",arr);
}