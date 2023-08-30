#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int main(){

    int N,M1,M2,cnt;
    int wordcnt1=0,wordcnt2=0;

    int max = -1,min = 100000;
    char str[100];
    char rst[100]={};


    char maxstr[100]={},minstr[100]={};
    scanf("%d %d %d",&N,&M1,&M2);getchar();
    //정수 N과 M1, M2를 입력받고

    for(int i=0;i<N;i++){
        gets(str);
        if((int)strlen(str) > max){
            strcpy(maxstr,str);
            max = (int)strlen(str);
        }
        if((int)strlen(str) < min){
            strcpy(minstr,str);
            min = (int)strlen(str);
        }
    }
    //가장 긴 문자열의 M1 번째 단어와
    // 가장 짧은 문자열의 M2 번째 단어를 합성
    char word1[20][100]={},word2[20][100]={};

    for(int i=0;i<(int)strlen(maxstr);i++){
        if(maxstr[i] !=' ' || i == (int)strlen(maxstr) -1 ){//공백이 아니면 == 문자이면
            word1[wordcnt1][cnt] = maxstr[i];
            cnt++;
        }
        else{  
            wordcnt1 ++;
            cnt = 0;
        }
    }
    cnt = 0;

    for(int i=0;i<(int)strlen(minstr);i++){
        if(minstr[i] !=' ' || i == (int)strlen(minstr) -1 ){//공백이 아니면 == 문자이면
            word2[wordcnt2][cnt] = minstr[i];
            cnt++;
        }
        else{  
            wordcnt2 ++;
            cnt = 0;
        }
    }

    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(i==M1 && j == M2){
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

    printf("%s\n%s\n%s",maxstr,minstr,rst);

    // printf("%s\n%s",maxstr,minstr);


    
    // strcpy, strcat, strcmp 함수를 각각 최소 1회 이상 사용


}
/*
5 4 2

book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake icecream
july august september october november december


*/