#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char arr[1001]={},*parr = arr,word[102][100];
    strcpy(word[100]," \n");
    strcpy(word[101]," ");
    // word[100] = " \n";
    // word[101] = "  ";
    

    int N,len= 0,cnt=0,wordcnt=0;
    int val = 0;
    int max = -1,samemax=1000,rstnum;
    gets(arr);
    scanf("%d",&N);
    // for(int i=0;;i++){
    //     scanf("%c",(parr+i));
    //     if(*(parr+i)=='\n') break;
    // }
    char *token;
    token = strtok(arr,word[100]);
    while(token != NULL){
        // printf("token = %s\n",token);
        strcpy(word[cnt],token);
        token = strtok(NULL,word[100]);
        cnt ++;
    }
    // printf("cnt = %d",cnt);
    
    for(int j=0;j<cnt;j++){
        max = -1;
        // printf("-");
        for(int i=0;i<cnt;i++){
            if((int)strlen(word[i])>max){ 
                max = (int)strlen(word[i]);
                // printf("max = %d\n",max);
                rstnum = i;
            }
        }
        val ++;
        if(val == N){
            printf("%s",word[rstnum]);
            break;
        }
        strcpy(word[rstnum]," ");
        // // word[rstnum] = " ";
    }
    // printf("val %d",val);
}
//최대 N개의 단어를 포함하고 최대 길이가 M인
//영어 소문자로 이루어진 문자열을 입력받음

//단어와 단어는 공백으로 분리 됨.

//문자열에 포함된 다너들을 길이가 가장 긴 단어부터 짧은 단어까지 정렬

//K번째 위치의 단어를 출력하라.

//abc def ghi jklm opqrst