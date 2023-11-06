#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int N,M,cnt,fir[10000000],sec[10000000];
    scanf("%d",&N);//정렬해야함.
    for(int i=0;i<N;i++)scanf("%d",&fir[i]);

    scanf("%d",&M);
    for(int i=0;i<M;i++)scanf("%d",&sec[i]);
    
    for(int i=0;i<M;i++){
        cnt = 0;
        for(int j=0;j<N;j++){
            if(sec[i]==fir[j]) {cnt = 1;break;}
        }printf("%d ",cnt);
    }
} 
/*

*/