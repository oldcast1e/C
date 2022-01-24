#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int x,y,key = 0;
    char word = 'a';
    scanf("%d %d",&x,&y);

    char **str = NULL;
    str = (char **)malloc(y*sizeof(char*));
    for(int i=0;i<x;i++) str[i] = (char *)malloc(x*sizeof(char));

    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            str[i][j] = word;
            word++;
            // printf("<>");
            if(word>'z' && key == 0){
                word = 'A';
                key = 1;
            }
            if(word > 'Z' && key == 1){
                 word = 'a';
                 key = 0;
            }
        }
    }

    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            printf(" %c",str[i][j]);
        }
        printf("\n");
    }


}