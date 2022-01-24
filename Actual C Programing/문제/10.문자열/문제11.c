#include  <stdio.h>
#include<string.h>
int main(){
    char str1[80],str2[10];
    char *pstr1 = str1,*pstr2 = str2;
    int str1len = strlen(str1),str2len = strlen(str2);
    int key=0,rst=0,cnt;

    scanf("%s",str1),scanf("%s",str2);
    for(int i=0;i<str1len;i++){
        if(*(pstr1+i)==*pstr2)key = 1;

        if(key==1){
            cnt = 0;
            for(int j=0;j<str2len;j++){
                if(*(pstr1+i+j)==*(pstr2+j)) cnt++;
            }
            if(cnt==str2len) rst = 1;
            key = 0;
        }
    }
    printf("%d %d",(int)strlen(str1),rst);
}