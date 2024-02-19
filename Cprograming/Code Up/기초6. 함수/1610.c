#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *mysubstr(char *str, int start, int count){
    char *rst[100],cnt=0;
    for(int i=start;i<start+count;i++){
        // printf("%c ",str[i]);
        *rst[cnt] = str[i]; 
        printf(">%d %c",i,*rst[cnt]);
        cnt++;
    }
    // 함수 처리부
    printf(">>>%s",*rst);
    return *rst;
}

int main(){
    int start,count;
    char arr[100]; scanf("%s",arr);
    scanf("%d %d",&start,&count);

    char *rst = mysubstr(arr,start,count);
    printf("%s",rst);
    

    
} 
/*

*/