#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char str[100];
    gets(str);
    int len = strlen(str);
    int wordnum = 0,x=0,y=0;

    int cnt = 0;

    for(int i=0;i<len;i++) if(str[i]==' ')wordnum ++;
    wordnum ++;//단어 개수
    // printf("%d",wordnum);
    
    //포인터 배열에 연결되는 각 문자 배열은 단어의 길이+1의 크기

    char **rst = NULL;
    rst = (char **)malloc((wordnum)*sizeof(char *));
    for(int i=0;i<wordnum;i++) rst[i] = (char *)malloc(wordnum*sizeof(char)+1);
    //포인터 배열의 크기는 단어의 수와 같음
    
    
    for(int i=0;i<len;i++){
        if(str[i] != ' ' && str[i] != '\n' ){
            rst[y][x] = str[i];
            x++;
        }
        else{
            x = 0;
            y++;
        }
    }
    for(int i=0;i<y+1;i++)printf("%s\n",rst[i]);
}
/*
(1) 공백을 포함하는 하나의 문자열을 입력받고, 
입력받은 문자열을 단어로 나누어 동적으로 할당 받은 2차원 배열(포인터 배열에 연결된 문자 배열)에 저장한다. 

단, 포인터 배열의 크기는 단어의 수와 같아야 하며, 
포인터 배열에 연결되는 각 문자 배열은 단어의 길이+1의 크기여야 한다.
즉, 포인터 배열을 동적으로 할당받고, 각 문자 배열을 동적으로 할당 받는다.

(2) 저장된 단어들을 길이가 가장 긴 단어부터 짧은 단어까지 정렬하여 출력한다. 
길이가 같은 단 어는 사전 순서상 빠른 단어부터 정렬한다.
*/