#include  <stdio.h>
#include  <string.h>
int main(){
    
    char str[100],*pstr = str;
    char word[100]="",*pw = word;
    int N,cnt=0,wcnt=0;
    gets(str);
    scanf("%d",&N);
    for(int i=0;i<strlen(str);i++){
        if(*(pstr+i)!=' '  || *(pstr+i)!='\0' ){
            *(pw+wcnt) = *(pstr+i);
            wcnt ++;
        }
        else {
            cnt ++;
            if(cnt == N){
                // printf("wcnt = %d\n",wcnt);
                printf("%s",pw);
                break;
            }
            wcnt = 0;
            for(int i=0;i<100;i++) *(pw + i) = ' ';
            // // printf("<befoe : %s",word);
            // printf("before:");
            // puts(word);
            // strcpy(word," ");
            // printf("after:");
            // puts(word);
        }
        // if(*(pstr+i)==' ' ||*(pstr+i)=='\0' ){
        //     cnt++;
        //     if(cnt == N) break;
        //     wcnt = 0;
        // } 
        // if(wcnt == 0){
        //     printf("-");
        //     strcpy(word,"");
        // }
        // *(pw+wcnt) = *(pstr+i);
        // wcnt ++;

    }
    // printf("%s",word);


}