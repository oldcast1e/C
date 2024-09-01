#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#define swap(tmp, x,y)do{tmp = x; x = y; y=tmp;}while(0)
//배열 요소를 역순으로 정렬하는 과정을 일일히 출력하는 프로그램을 작성하라

void reverse(char *rst){
    int rep = (int)strlen(rst),tmp;
    for(int i=0;i<rep/2;i++){
        swap(tmp,rst[i],rst[rep - i -1]);
        printf("a[%d]과 a[%d]를 교환합니다.\n",i,rep-i-1);
        for(int i=0;i<rep;i++) printf("%d ",rst[i]);printf("\n");
    }

}

int main(){
    char spr[] = " ,\n",str[10000],*pstr = str;
    gets(str);
    int num = strlen(str),cnt = 0;
    // printf("num = %d",num);
    char *rst = NULL;
    rst = (char *)malloc(sizeof(char)*num);

    char *token = strtok(str,spr);
    while(token != NULL){
        // printf("Token: %s\n",token);
        rst[cnt] = atoi(token); cnt ++;
        token = strtok(NULL,spr);
    }
    reverse(rst);



    // for(int i=0;i<cnt;i++) printf("%d ",rst[i]);
}
// 1 2 3 4 5 6 7 7