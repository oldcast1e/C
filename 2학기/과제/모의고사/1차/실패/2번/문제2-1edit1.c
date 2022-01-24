#include  <stdio.h>
#include  <string.h>
int main(){
    
    char str[100],*pstr = str;
    char word[100],*pw = word;

    strcpy(word,"");

    int N,cnt=0,wcnt=0;
    gets(str);
    scanf("%d",&N);
    
    for(int i=0;i<strlen(str);i++){
        if(*(pstr+i)==' ' || *(pstr+i) == '\0'){
            cnt ++;
            if(cnt == N){
                printf("%s",word);
                wcnt = 0;
            } 
            else{ 
                strcpy(word,"\0");
                wcnt = 0;
            }
        }
        *(pw+wcnt)  = *(pstr+i);
        wcnt ++;
        
    }


}