#include<stdio.h>
int main(){

    int N,M,K;
    scanf("%d %d",&N,&M);
    if(N>M){
        if(M*M == N)
            printf("%d*%d=%d",M,M,N);
    
        else    
            printf("none");
    }
    else
        if(N*N == M)
            printf("%d*%d=%d",N,N,M);
        else    
            printf("none");
}    