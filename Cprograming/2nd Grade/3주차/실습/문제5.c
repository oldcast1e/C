#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rst = 0;
void hanoi(int n, char start, char end, char tmp){
    rst ++;
    if(n==1) printf("%c %c\n",start,end);
    else{
        hanoi(n-1,start,tmp,end);
        printf("%c %c\n",start,end);
        hanoi(n-1,tmp,end,start);
    }
}
int main(){
    int num; 
    //printf("탑의 개수를 입력하세요: ");
    scanf("%d",&num); 
    hanoi(num,'A','C','B');
    // printf("재귀 횟수: %d",rst);
}