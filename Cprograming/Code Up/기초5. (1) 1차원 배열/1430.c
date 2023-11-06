#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int N,M,cnt,fir[1000000],sec[1000000];
    int min=1000000,max=-1,idx;
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&fir[i]);

    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            if(fir[i]>fir[j]){cnt = fir[i];fir[i] = fir[j];fir[j]=cnt;}cnt = 0;

    for(int i=0;i<N;i++)printf("%d ",fir[i]);
    scanf("%d",&M);
    for(int i=0;i<M;i++)scanf("%d",&sec[i]);

    int chc,key=0;
    for(int i=0;i<M;i++){
        chc = N; key=0;
        // while(0<chc && chc <= N){
        //     if(sec[i] < fir[chc/2])
        //     else if(sec[i] > fir[chc/2])
        //     else if(sec[i] == fir[chc/2]){key=1;break;}
        // }
        printf("%d ",key);
    }
    // for(int i=0;i<M;i++){
    //     cnt = 0;
        
    //     //if(sec[i]==fir[j]) {cnt = 1;break;}
    //     printf("%d ",cnt);
    // }
} 
/*

*/