#include  <stdio.h>
int main(){
    
    int N,gamekey=1,cnt=0,rstcnt=0;
    scanf("%d",&N);
    if(N<1 || N>100)
        gamekey = 0;

    int score[100];
    int rst[100];

    if(gamekey==1){//N의 값이 가용 범위이면,

        while (1){//(ㄱ)

        for(int i=0;i<N;i++){
            scanf("%d",&score[i]);
            if(score[i]>100 || score[i]<0)
                break;//(ㄱ) 반복문 탈출
        }
        //////////
        while(N>cnt){
            if(score[cnt]>score[cnt+1]){
                rst[cnt] = score[cnt];
            }
            else{
                rst[cnt] = score[cnt+1];
            }
            cnt +=2;

            

        }
        // for(int i =cnt;i<=N;i++){
        //     if(score[2*i-1]>score[2*i]){
        //         score[2*i-1]=score[2*i];
        //     }
        //     else    
        //         score[2*i]=score[2*i-1];
        // }


        }
    }

}
