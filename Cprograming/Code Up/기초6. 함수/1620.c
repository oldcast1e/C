#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cal(int n){
    int tmp = n,val = 0;
    while(tmp > 0){val += tmp%10; tmp/=10;}
    // printf(">val = %d\n",val);
    if(val < 10) return val;
    else return cal(val);
    // else n = cal(n);
}

int main(){
    int n;scanf("%d",&n);
    printf("%d",cal(n));
} 
/*

*/