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
        if(*(pstr+i)!= ' '){
            cnt++;
            // printf("---==--");
        }
        else{
            // printf("><><");
            strcpy(word,"");
            for(int j =i-cnt;j<i;j++){
                *(pw + wcnt) = *(pstr+j);
                printf("<%c>",*(pstr+j));
                wcnt ++;
                // printf("%d",wcnt);
            }
            wcnt = 0;
            *(pw + wcnt) = '\0';
            printf("\n");

        }

        
    }


}