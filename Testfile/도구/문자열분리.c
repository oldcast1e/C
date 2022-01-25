#include  <stdio.h>
#include <string.h>
int main(){
    char arr[100] = "Sejong Univ Intelligence Mechanical & Electrical Engineering";
    char spr[] = " ,\n";
    char *token = strtok(arr,spr);
    while(token != NULL){
        printf("Token: %s\n",token);
        token = strtok(NULL,spr);
    }
    printf("Og arr: %s",arr);


}