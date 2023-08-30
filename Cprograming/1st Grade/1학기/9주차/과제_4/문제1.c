#include  <stdio.h>
int main(){
    
    int N,gamekey=1,cnt=0,rstcnt=0;
    scanf("%d",&N);
    // if(N<1 || N>100)
    //     break;
    int score[100];
    int rst[100];

    for(int i=0;i<N;i++){
            scanf("%d",&score[i]);
            if(score[i]>100 || score[i]<0)
                break;//(ㄱ) 반복문 탈출
    }

    while (1){//(ㄱ)
        //////////
        while(N>cnt){
            if(score[cnt]>score[cnt+1]){
                rst[rstcnt] = score[cnt];
            }
            else{
                rst[rstcnt] = score[cnt+1];
            }
            cnt +=2;
            if(cnt>0)
                rstcnt = cnt/2;
            
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
