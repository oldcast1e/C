#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int N,D,cnt = 0;
    int *num = NULL;
    scanf("%d",&N);
    
    num = (int*)malloc(N*sizeof(N));
    for(int i=0;i<N;i++) scanf("%d",&num[i]);
    scanf("%d",&D);

    num = (int*)realloc(num,N-D);
    // for(int i=N-1;i>=0;i--){
    //     if(cnt == D) break;
    //     free(num[i]);
    //     cnt ++;
    // }

    for(int i=0;i<N-D;i++) printf("%d",num[i]);



}