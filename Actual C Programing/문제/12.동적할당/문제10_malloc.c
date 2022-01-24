#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int size = 5,cnt = 0;
    int *num = NULL;
    num = (int*)malloc(size*sizeof(int));
    while(1){
        scanf("%d",&num[cnt]);
        if(num[cnt]==-1){
            
            break;
        }
        cnt++;
        int *tmp = (int*)malloc((size+3)*sizeof(int));
        for(int i=0;i<size;i++) tmp[i] = num[i];
        free(num);

        num = tmp;
        size += 3;

    }
    for(int i=cnt;i>=0;i--) printf("%d ",num[i]);
}