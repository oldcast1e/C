#include  <stdio.h>
int main(){
    
    int N,er=0;
    int cnt =0;
    int score[N];
    scanf("%d",&N);
    while(1){

        if(N<1 || N>100){
            printf("ERROR");
            break;
        }
            

        for(int i=0;i<N;i++){
        scanf("%d",&score[i]);
        if(score[i]<0 || score[i]>100)
            er ++;
        }
        if(er>0){
            printf("ERROR");
            break;
        }

        for(int j=0;j<N-1;j++){
            
        }



    }


}
