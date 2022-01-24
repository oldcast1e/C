#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int N;
    scanf("%d",&N);
    getchar();
    char **str = NULL;
    str = (char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++) str[i] = (char*)malloc(101*sizeof(char));

    for(int i=0;i<N;i++) gets(str[i]);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j){
                if(strcmp(str[i],str[j])<0){
                    char *tmp;
                    tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                    
                }
            }
        }
    }
    for(int i=0;i<N;i++) puts(str[i]);
    

    
}