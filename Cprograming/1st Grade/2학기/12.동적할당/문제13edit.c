#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int N,D;
    scanf("%d",&N);
    int *num =  NULL;
    int *tmp =  NULL;
    num = (int*)malloc(N*sizeof(int));

    for(int i=0;i<N;i++) scanf("%d",&num[i]);
    scanf("%d",&D);

    tmp = realloc(num,N-D);
    for(int i=0;i<N-D;i++) printf("%d\n",tmp[i]);

    free(num);
    // free(tmp);
}

/*
16011111 
16011123 
16011145

120111
15011123 
16011145 
16011300
*/