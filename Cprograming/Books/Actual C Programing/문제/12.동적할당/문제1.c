#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    int *num = NULL;
    num = (int *)malloc(N*sizeof(N));

    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    for(int i=N-1;i>=0;i--){
        printf("%d ",num[i]);
    }

}