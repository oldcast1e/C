#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

void reset(char *arr){
    for(int i=0;i<100;i++)arr[i] = '\0';
}
int main(){

    int M,N,cnt,space;
    char str1[100],str2[100];
    char word1[100],word2[100];

    char rst[100];
    scanf("%d %d",&M,&N);getchar();

    gets(str1);gets(str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    cnt = 0;space=-1;
    for(int i=0;i<len1;i++){
        if(str1[i]!=' '){
            word1[cnt] = str1[i];
            cnt++;
        }
        else if( i== len1-1){//문자열의 마지막인 경우
            word1[cnt] = str1[i];        
            space ++;
            if(space == M) break;
        }
        else{
            space ++;
            if(space == M) break;
            reset(word1);
            cnt = 0;
        }
    }
    // strcpy(word1,tmp);
    cnt = 0;space=-1;
    for(int i=0;i<len2;i++){
        if(str2[i]!=' '){
            word2[cnt] = str2[i];
            cnt++;
        }
        else if( i== len2-1){//문자열의 마지막인 경우
            word2[cnt] = str2[i];        
            space ++;
            if(space == N) break;
        }
        else{
            space ++;
            if(space == N) break;
            reset(word2);
            cnt = 0;
        }
    }
    // printf("%s %s\n",word1,word2);
    // strcat(word2,tmp);

    if(strcmp(word1,word2)>0){
        strcpy(rst,word2);
        strcat(rst,word1);
    }
    else{
        strcpy(rst,word1);
        strcat(rst,word2);
    }
    printf("%s",rst);
}
    
    



    // strcpy, strcat, strcmp 함수를 각각 최소 1회 이상 사용



/*
book desk pencil paper
orange apple banana lemon grape

book desk pencil paper
orange apple banana lemon grape
*/