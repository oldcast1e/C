#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char arr[1001]={},*parr = arr,word[102][100];
    strcpy(word[100]," \n");
    strcpy(word[101]," ");
    int N,len= 0,cnt=0,wordcnt=0;
    int max= -1000,rstnum,val = 0,cmpval;
    gets(arr);
    scanf("%d",&N);

    char *token;
    token = strtok(arr,word[100]);
    while(token != NULL){
        // printf("token = %s\n",token);
        strcpy(word[cnt],token);
        token = strtok(NULL,word[100]);
        cnt ++;
    }
    // printf("cnt = %d",cnt);
    for(int k=0;k<cnt;k++){
        for(int i=0;i<cnt;i++){
            cmpval = 0;
            for(int j=0;j<cnt;j++){
                if(strlen(word[i])==strlen(word[j])){
                    cmpval += (-1)*strcmp(word[i],word[j]);
                }
                else{
                    cmpval += strcmp(word[i],word[j]);
                }
            }  
            if(cmpval>max){
                max = cmpval;
                rstnum = i;
            }
        }
        val ++;
        if(val == N){
            printf("%s",word[rstnum]);
            break;
        }
        strcpy(word[rstnum]," ");
    }
    // printf("val %d",val);
}

//abc def ghi jklm opqrs