#include  <stdio.h>
int main(){
    
    int N,M,chn,tmp;

    int A[20]={0,};
    for(int i=1;i<=20;i++){
        A[i-1] = i;
    }

    scanf("%d",&M);

    for(int i=19;i<20-M;i--){//19~16

        if(i==19)
            chn = A[i];//20을 chn에 저장

        A[i] = A[i-1]; 

        if(i==20-M)//i가 16일때
            A[20-M] = chn;
    }

    for(int i=0;i<20;i++){
        printf("%d ",A[i]);
    }

}
