#include  <stdio.h>
#include  <string.h>

int main(){

    char str[101],*pstr= str;
    char word[100][100];
    char minlenword[100];
    char maxlenword[100];
    // char word2[100][100];
    int N,x,y;

    int minlen = 1001;
    int maxlen = -1;

    int minlenwordlen = 0;
    int maxlenwordlen = 0;
    scanf("%d",&N);getchar();

    for(int i=0;i<N;i++){
        gets(str);
        x=0,y=0;
        int len  = strlen(str);

        for(int i=0;i<len;i++){
            if(*(pstr+i)!=' '){
                word[x][y] = *(pstr+i);
                y++;
            }
            else{
                word[x][y] = '\0';
                x ++;
                y = 0;
            }
        }   

        for(int i=0;i<=x;i++){
            for(int j=i;j<=x;j++){
                char tmp[100];
                strcpy(tmp,"\0");
                if(strcmp(word[i],word[j])>0){
                    strcpy(tmp,word[i]);
                    strcpy(word[i],word[j]);
                    strcpy(word[j],tmp);
                }
            }
        }

        if(minlen>len){
            minlen = len;
            strcpy(minlenword,"\0");
            strcpy(minlenword,word[0]);
            
            // minlenwordlen = strlen(minlenword);
            // strncpy(minlenword,minlenword,minlenwordlen);
        }
        if(len > maxlen){
            maxlen = len;
            strcpy(maxlenword,"\0");
            strcpy(maxlenword,word[x]);
            strcat(maxlenword,"\0");
            // maxlenwordlen = strlen(maxlenword);
        }
    }

    printf("%s\n",minlenword);
    printf("%s",maxlenword);


}

/*
입력된 문자열 중 가장 짧은 문자열에 포함된 사전적 순서가 가장 빠른 단
어와 입력된 문자열 중 가장 긴 문자열에 포함된 사전적 순서가 가장 늦은 단어를 각각 출력하는
프로그램을 작성하시오.

*/
//why so happy
//icecream makes everything better