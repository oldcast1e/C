#include  <stdio.h>
#include<string.h>
int main(){
    char str1[20],str2[20],rst[20];
    char tmp[20],chg[20];
    char *pstr1 = str1,*pstr2 = str2;
    int pos,cnt1=0,cnt2=0,dir;
    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%d",&pos);
    scanf("%d",&dir);
    strncat(rst,str1,pos);
    if(dir==0)strcat(rst,str2);
    else{//역순->str2 반대로 접합
        for(int i=(int)strlen(str2)-1;i>=0;i--){
            chg[cnt2] = *(pstr2+i);
            cnt2++;
        }
        strcat(rst,chg);
        // printf("chg = %s\n",chg);
    }
    // strcat(rst,str2); 역순 정순 접합
    for(int i=pos;i<(int)strlen(str1);i++){
        tmp[cnt1] = *(pstr1+i);
        cnt1++;
    }
    strcat(rst,tmp);
    printf("%s",rst);





}
//공백x의 영문 문자열 str1,2와 삽입위치를 입력받은 후, str1의 해당 위치에 str2를 삽입하는 프로그램