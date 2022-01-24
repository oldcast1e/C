#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    char str[101],*pstr= str;
    scanf("%s",str);
    int len = strlen(str);

    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            if(*(pstr+i) > *(pstr+j)){
                char tmp;
                tmp = *(pstr+i);
                *(pstr+i) = *(pstr+j);
                *(pstr+j) = tmp;
            }
        }
    }
    printf("%s",str);


}