#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    char str[101],*pstr= str;
    gets(str);
    int len = strlen(str);
    int max = -1,cnt=0;

    int key;

    for(int i=0;i<len;i++){
        
        if('a'<= *(pstr+i) && *(pstr+i) <= 'z'){
            cnt ++;
            key = 0;
        }
        else key ++;
        
        if(key == 1){
            if(*(pstr+i-1)){//
                for(int j= i-cnt;j<i;j++){
                    printf("%c",*(pstr+j));
                }
                printf("\n");
                if(cnt> max) max = cnt;
                cnt = 0;
            }
            key ++;
        }
    }
    printf("%d",max);


}