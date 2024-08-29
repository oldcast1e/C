#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void hanoiTower(int n, char start, char end, char tmp){
    if(n == 1) printf("[%c]->[%c]\n",start,end);
    else{
        hanoiTower(n-1,start,tmp,end);
        printf("[%c]->[%c]\n",start,end);
        hanoiTower(n-1,tmp,end,start);
    }
}
int main(){
    int n = 3;
    hanoiTower(3,'A','C','B');
}