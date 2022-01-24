#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char arr[1001],*parr = arr;
    int word[100],*pw= word,cnt;
    int N,len= 0,cnt=0,wordcnt=0;
    
    for(int i=0;;i++){
        scanf("%c",(parr+i));
        if(*(parr+i) == '\n') break;
        len ++;
    }
    scanf("%d",&N);

    for(int i=0;i<len;i++){
        if(*(parr+i)!=' ') cnt++;
        else if(*(parr+i)==' '){
            for(int j=1;j<=cnt;j++){
                
            }
            wordcnt ++;
        }
    }

}
//최대 N개의 단어를 포함하고 최대 길이가 M인
//영어 소문자로 이루어진 문자열을 입력받음

//단어와 단어는 공백으로 분리 됨.

//문자열에 포함된 다너들을 길이가 가장 긴 단어부터 짧은 단어까지 정렬

//K번째 위치의 단어를 출력하라.