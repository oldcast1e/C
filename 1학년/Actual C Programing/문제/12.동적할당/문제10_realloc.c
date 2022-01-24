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

        num = realloc(num,size+3);
        if(num == NULL){
            printf("Error");
            return -1;
        }
        size += 3;

    }
    for(int i=0;i<cnt;i++) printf("%d ",num[i]);
}