#include  <stdio.h>
#include<string.h>
int main(){
    char str1[20],str2[20],rst[20],tmp[20];
    char *pstr1 = str1;
    int pos,cnt=0;
    
    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%d",&pos);

    strncat(rst,str1,pos);
    strcat(rst,str2);
    for(int i=pos;i<(int)strlen(str1);i++){
        tmp[cnt] = *(pstr1+i);
        cnt++;
    }
    strcat(rst,tmp);
    printf("%s",rst);





}
//공백x의 영문 문자열 str1,2와 삽입위치를 입력받은 후, str1의 해당 위치에 str2를 삽입하는 프로그램