#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int start,count,cnt=0;
char arr[100],rst[100];

char *mysubstr(char *str, int start, int count){
    for(int i=start;i<start+count;i++){
        rst[cnt] = str[i]; cnt++;
        // printf(">%c",str[i]);
    }
    return 0;
}

int main(){
    scanf("%s",arr);scanf("%d %d",&start,&count);
    mysubstr(arr,start,count);
    // char *rst = mysubstr(arr,start,count);
    // printf("%s",rst);
    for(int i=0;i<cnt;i++)printf("%c",rst[i]);
    

    
} 
/*

*/