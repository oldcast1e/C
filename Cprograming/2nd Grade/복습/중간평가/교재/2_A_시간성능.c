#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
    clock_t start, stop;
    start = clock();
    int cnt = 1;
    for(int i=0;i<1000000;i++);
    stop = clock();

    double  duration = (stop-start)/CLOCKS_PER_SEC;
    printf("duration = %lf",duration);
}