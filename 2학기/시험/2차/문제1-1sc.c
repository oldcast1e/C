#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int main(){

    int M,N,cnt;
    int wordcnt1=0,wordcnt2=0;
    char word1[20][100]={},word2[20][100]={};
    char str1[100],str2[100];

    char rst[100]={};

    scanf("%d %d",&M,&N); getchar();
    gets(str1);gets(str2);
    cnt = 0;
    for(int i=0;i<(int)strlen(str1);i++){
        if(str1[i] !=' ' || i == (int)strlen(str1) -1 ){//공백이 아니면 == 문자이면
            word1[wordcnt1][cnt] = str1[i];
            cnt++;
        }
        else{  
            wordcnt1 ++;
            cnt = 0;
        }
    }
    cnt = 0;

    for(int i=0;i<(int)strlen(str2);i++){
        if(str2[i]!=' ' || i == (int)strlen(str2) -1 ){//공백이 아니면 == 문자이면
            word2[wordcnt2][cnt] = str2[i];
            cnt++;
        }
        else{  
            wordcnt2 ++;
            cnt = 0;
        }
    }

    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(i==M && j == N){
                if(strcmp(word1[i],word2[j])>0){
                    strcpy(rst,word2[j]);
                    strcat(rst,word1[i]);
                }
                else{
                    strcpy(rst,word1[i]);
                    strcat(rst,word2[j]);
                }
            }
        }
    }
    printf("%s",rst);
    // printf("%s",word1[M]);

    // printf("%s %s",word1[M],word2[N]);

}
/*
book desk pencil paper
orange apple banana lemon grape

book desk pencil paper
orange apple banana lemon grape
*/