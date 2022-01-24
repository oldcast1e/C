#include  <stdio.h>
#include  <string.h>

int main(){

    char str[101],*pstr= str;
    char word[100][100];

    int x=0,y=0;
    gets(str);

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
    printf("%s",word[0]);

}

/*
사용자로부터 공백을 포함하는 하나의 문자열을 입력받고, 공백을 기준으로
단어로 나누어 (공백과 공백 사이의 문자열을 하나의 단어라 한다). 
입력된 문자열에 나타난 단어중, 
사전적 순서가 가장 빠른 단어를 출력하는 프로그램을 작성하시오.
 - 문자열은 알파벳 소문자로만 구성된다고 가정하며, 문자열의 길이는 최대 100이다. - 입력된 문자열의 첫 문자는 공백이 아니며, 단어와 단어 사이에는 공백 문자가 하나만 존재한
다.
 - 문자열 입력 시 gets 사용하고, 문자열을 화면으로 출력할 때 %c 사용금지한다

*/