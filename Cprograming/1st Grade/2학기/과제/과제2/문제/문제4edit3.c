#include  <stdio.h>
#include  <string.h>
void s_cneck(char *p,char *q){//p = str 
    char *i;
    int rst = 0;
    for(i = p;i<=q;i++){
        if(*i == '\0') break;
        if('a'<= *i && *i <= 'z') rst ++;
    }
    if(rst!=0) printf("%d\n",rst);
}
int main(){
    int M,K1,K2,result;
    int len;
    char str[100] = {0,},tmp[10]={0},*pstr= str;
    for(int i=0;i<10;i++) tmp[i] = 'K';
    scanf("%d",&M);scanf("%d",&K1);scanf("%d",&K2);
    getchar();
    for(int i=0;i<M;i++){
        gets(str);
        s_cneck(str+K1,str+K2);
    }
}
