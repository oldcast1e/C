#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    char str[101],*pstr= str;
    char word[100][100];
    gets(str);
    int len = strlen(str);
    int a=0,b=0;

    for(int i=0;i<=len;i++){
        if(*(pstr+i)!=' '){
            word[a][b] = *(pstr+i);
            b++;
        }
        else{
            a++;
            b = 0;
        }
    }
    
    for(int i=0;i<=a;i++){
        puts(word[i]);
    }

    for(int i=0;i<=a;i++){
        for(int j=i;j<=a;j++){
            
            if(strcmp(word[i],word[j])>0){
                char tmp[21];
                strcpy(tmp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],tmp);

            }
        }
    }
    for(int i=0;i<=a;i++){
        puts(word[i]);
    }




}