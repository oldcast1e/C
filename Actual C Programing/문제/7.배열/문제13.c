#include  <stdio.h>
int main(){
    
    int M,N,cnt=1;
    int A[20][20],B[20][20];
    scanf("%d %d",&M,&N);
    int rst[2];
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&B[i][j]);
        }
    }
//////////
    for(int i=0;i<M;i++){//열
        for(int j=0;j<cnt;j++){//행
            A[i][j+1]=A[i][j];
        }
       
    }
}
