#include<stdio.h>
int main(){
    
    int N;
    scanf("%d",&N);
    if(N%4==0){
        if(N%100==0){
            if(N%400==0)
                printf("leap year");
            else
                printf("common year");
        }
        else
            printf("leap year");
    }
    else   
        printf("common year");
}