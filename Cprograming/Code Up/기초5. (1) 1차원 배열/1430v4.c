#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int N,M,*fir,*sec,cnt;
    scanf("%d",&N);fir = (int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)scanf("%d",&fir[i]);

    for(int i=0;i<N;i++)//정렬
        for(int j=i;j<N;j++)
            if(fir[i]>fir[j]){cnt = fir[i];fir[i] = fir[j];fir[j]=cnt;}

    scanf("%d",&M);sec = (int*)malloc(M*sizeof(int));//M개의 각각의 질문 -> fir 배열에 대한 확인 필요
    for(int i=0;i<M;i++)scanf("%d",&sec[i]);
    for(int i=0;i<M;i++){
        int LOW,MID,HIGH,key = 0;

        LOW = 0;
        HIGH = N -1;
        do{
            MID = (LOW + HIGH)/2;
            if(fir[MID] == sec[i]){key = 1; break;}
            else if(fir[MID] < sec[i]) LOW = MID + 1;
            else HIGH = (MID -1);

        }while(LOW <= HIGH);
        printf("%d ",key);
    }
} 
/*

*/