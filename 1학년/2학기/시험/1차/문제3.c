#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char str1[101],*pstr1= str1;
    char str2[11],*pstr2= str2;
    char str3[11],*pstr3= str3;

    char word[100][100]={{0}};
    int x=0,y=0;

    gets(str1);gets(str2);gets(str3);

    int len1 = strlen(str1);
    int wordlen;
    for(int i=0;i<len1;i++){
        if(*(pstr1+i)!=' ' && (*(pstr1+i)!='.')){
            word[x][y] = *(pstr1+i);
            y++;
        }
        // if((*(pstr1+i)=='.')){
        //     word[x][y] = *(pstr1+i);
        //     y++;
        // }
        else{
            word[x][y] = '\0';
            x ++;
            y = 0;
        }
    }

    for(int i=0;i<x;i++){
        wordlen = strlen(word[i]);
        // printf("<%s %s>\n",word[i],str2);
        if(strncmp(word[i],str2,wordlen)==0){
            // printf("(%s %s)\n",word[i],str2);
            char tmp[100];
            strcpy(tmp,word[i]);
            strcpy(word[i],str3);
            strcpy(str3,"");
        }
    }

    for(int i=0;i<x;i++){
        printf("%s ",word[i]);
    }


}
