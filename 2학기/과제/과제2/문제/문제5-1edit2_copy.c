#include<stdio.h>
#include<string.h>

#define STR_NUM 5
#define STR_LEN 20

int main(){

    int i=0,j=0;
    char str[STR_NUM][STR_LEN];
    char temp[STR_LEN];

    for(i=0;i<STR_NUM;i++) gets(str[i]);

    for(i=0;i<STR_NUM-1;i++){
        for(j=0;j<(STR_NUM-i);j++){
            if(strlen(str[j])>strlen(str[j+1])){

                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
    }
    for(i=0;i<STR_NUM;i++)puts(str[i]);
}
//hello world apple key pen
//abc def ghi jklm opqrst