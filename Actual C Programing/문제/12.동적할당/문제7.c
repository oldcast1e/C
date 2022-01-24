#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int N;
    char word[100];
    scanf("%d",&N);
    getchar();
    char **str = NULL;
    str = (char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++) str[i] = (char*)malloc(101*sizeof(char));

    for(int i=0;i<N;i++) gets(str[i]);

    int minlen  = strlen(str[0]);
    for(int i=1;i<N;i++){
        if(minlen > (int)strlen(str[i])){
            minlen = (int)strlen(str[i]);
            strcpy(word,str[i]);
        }
    }
    printf("%s",word);
}