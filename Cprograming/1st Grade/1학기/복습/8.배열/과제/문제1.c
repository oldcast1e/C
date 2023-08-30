#include  <stdio.h>
int main(){
    
    int N,errorcode=0,spn=0;
    int score[100];
    scanf("%d",&N);
    if(0>N || N>100) errorcode = 1;
    if(errorcode !=1){
        for(int i=0;i<N;i++){
            scanf("%d",&score[i]);
            if(score[i]>100 || score[i]<0) errorcode = 1;
        }
    }
    while(N>0){
        if(errorcode ==1){
            printf("ERROR");
            break;
        }
        if(N==1)break;

        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가

        for(int i=0;i<N;i+=2){
            if(score[i]>=score[i+1]){
                printf("%d ",score[i]);
                score[i/2] = score[i];
                score[i / 2 + 1] = 0;
            }
            else{
                printf("%d ",score[i+1]);
                score[i/2] = score[i+1];
                score[i / 2 + 1] = 0; 
                
            }
        }
        if(N%2==0) N /= 2;//다음 비교해야 할 횟수로 바꾼다.
        else N = (N/2)+1; //홀수 일때
    }
}




/*
90 95 80 85 81 82 79 77
95 0  85 0  82 0  79 0
N = 4

*/