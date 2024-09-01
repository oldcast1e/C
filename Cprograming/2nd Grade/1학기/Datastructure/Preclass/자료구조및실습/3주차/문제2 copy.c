#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int div_cal(int n){
    int tmp = n,cnt = 0,rst = 1;
    while(tmp>0){
        tmp/=10; cnt++;
    }return cnt-1 ;
    //3
}
void print(int n,int num[]){
    int cal=1,cnt = div_cal(n);  
    for(int i=0;i<cnt;i++) cal *=10;
    if(n > 0){
        num[cnt] = n /cal;
        n -= (n /cal) *cal;
    }
    printf(">%d",n);

}

int main(){
    int n,*num; scanf("%d",&n);
    int size = div_cal(n);printf("size =  %d\n",size);
    num = (int *)malloc(sizeof(int)*size);
    print(n,num);

    
} 
/*

*/