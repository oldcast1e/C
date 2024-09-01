#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int div_cal(int n){
    int tmp = n,cnt = 0,rst = 1;
    while(tmp>0){
        tmp/=10; cnt++;
    }cnt --;
    for(int i=0;i<cnt;i++) rst *=10;
    return rst; 
}

void print(int n){
    int val = div_cal(n); 
    printf("%d\n",n/val);
    if(n % val > 0 || n > 0)print(n % val);
    // printf("div_cal = %d",val);


}

int main(){
    int n; scanf("%d",&n);
    print(n);

    
} 
/*

*/