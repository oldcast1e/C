#include  <stdio.h>
#include  <string.h>
void s_cneck(char *p,char *q){//p = str || q = strlen(str)
    char *i;
    int rst = 0;
    for(i = p;i<=q;i++){
        if('a'<= *i && *i <= 'z') rst ++;
    }
    if(rst!=0) printf("%d\n",rst);
}
int main(){
    int M,K1,K2,result;
    int len;
    char str[100] = {0,},tmp[10]={0},*pstr= str;
    for(int i=0;i<100;i++) tmp[i] = 'K';
    // puts(tmp);printf("\n");
    // strncat(str,tmp,5);
    // puts(str);


    scanf("%d",&M);

    scanf("%d",&K1);
    scanf("%d",&K2);
    printf("(K1 = %d | K2  = %d)\n",K1,K2);

    getchar();
    for(int i=0;i<M;i++){
        // strcpy(str,tmp);
        gets(str);
        len = strlen(str); printf(">len: %d\n",len);
        // while(1){
        //     if(*(pstr+len-1) == '\0') break;
        //     if(*(pstr+len-1)!= '\0') *(pstr+len) = '0';
        //     len++;
        // }
        for(int i=0;i<100;i++)printf("%c",*(pstr+i));
        // printf("<1> str%d: ",i+1);
        // strcat(str,tmp);
        // // str[99] = '\0';

        // printf("<2> str%d: ",i+1);
        // puts(str);
        // str[strlen(str)] = 'A';
        // str[strlen(str)+1] = '\0';
        printf("<%c %c>\n",*(str+K1),*(str+K2));
        s_cneck(str+K1,str+K2);
    }
}
//공백을 포함하는 M개의 문자열을 입력받고, ILil
//각 문자열의 K1번째 문자부터 K2문자까지의 문자중에 알파벳 소문자의 개수를 세 출력하라.
// - 입력받는 문자열 M의 크기는 최대 200이다.
// - 소문자 개수가 0이면 출력에서 제외한다.
//=> 0번째도 있다고 가정한다.

//정수 M과 K1, K2를 입력받고, 공백이 포함된 M개의 문자열을 입력받는다. (M ≦ 10)

//알파벳 소문자의 개수를 출력하는 함수는 s_check 함수를 사용한다.

//  표준 문자열 처리함수는 strlen을 사용한다.

// 3
// 2 9
// ClanguageIsInteres ting 
//CCC CCCC
// LanguageC

// 3
// 2 7 
// ShootDanc e 
// SSSSS DDDD 
// RockInEve