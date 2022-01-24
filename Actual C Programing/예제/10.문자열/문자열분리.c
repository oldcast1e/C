#include  <stdio.h>
#include <string.h>
int main(){
    char arr[100] = "Sejong Univ Intelligence Mechanical & Electrical Engineering";
    char spastr[] = " ,\n";
    char *token = strtok(arr,spastr);
    while(token != NULL){
        printf("Token: %s\n",token);
        token = strtok(NULL,spastr);
    }
    printf("Og arr: %s",arr);


}