#include  <stdio.h>
int main(){

    int M1,M2,N1,N2;
    scanf("%d %d",&M1,&M2);
    scanf("%d %d",&N1,&N2);

    for(int i=N1;i<=N2;i++){//열
        for(int j=M1;j<=M2;j++){
            printf(" %d",i*j);
        }
        printf("\n");
    }
    
}