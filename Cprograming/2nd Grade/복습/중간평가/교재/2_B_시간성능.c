#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
    clock_t start, stop;
    start = time(NULL);
    int cnt = 1;
    for(int i=0;i<1000000;i++);
    stop = time(NULL);

    double  duration = (double)difftime(stop,start);
    printf("duration = %lf",duration);
}