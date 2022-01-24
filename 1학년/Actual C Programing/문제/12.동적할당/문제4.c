#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int N,len = 0,rsta=0,rstb=0;
    char *str = NULL;
    char a,b;
    scanf("%d",&N);
    getchar();
    str = (char*)malloc(N*sizeof(char));

    gets(str);
    scanf("%c %c",&a,&b);

    len = strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]==a) rsta++;
        if(str[i]==b) rstb++;
    }

    printf("%d %d",rsta,rstb);
    
    



}