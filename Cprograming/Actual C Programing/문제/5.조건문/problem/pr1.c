#include<stdio.h>

int main(){

    int N;
    if(N<0)
        printf("cold, indoor");
    else if(0<=N && N<40)
        printf("moderate, outdoor");
    else
        printf("hot, indoor");

}