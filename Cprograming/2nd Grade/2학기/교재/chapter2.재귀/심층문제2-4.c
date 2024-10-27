#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int rst = 0;

void rHanoi2(int n, int from, int aux, int to){
    rst ++;
    if(n==1) printf("move to from %d to %d\n",from,to);
    else{
        printf("move to from %d to %d\n",from,aux);
        rHanoi2(n-1,from,aux,to);
        printf("move to from %d to %d\n",aux,to);
    }
}

void rHanoi(int n, int start, int tmp, int end){
    rst ++;
    if(n==1) printf("[%d]->[%d]\n",start,end);
    else{
        rHanoi(n-1,start,end,tmp);
        printf("[%d]->[%d]\n",start,end);
        rHanoi(n-1,end,tmp,start);
    }
}



int main(){
    int num; 
    printf("탑의 개수를 입력하세요: ");scanf("%d",&num);
    rHanoi(num,1,3,2);
    // rHanoi2(num,1,3,2);
    // hanoi(num,1,3,2);
    printf("재귀 횟수: %d",rst);
}