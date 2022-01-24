#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char str[100],*pstr = str;
    char rsta[101],*prsta =  rsta;
    char val;
    int N,lena,rstcnt=0,num;

    gets(str);
    scanf("%d",&N);

    strcpy(rsta,"\0");
    lena = strlen(str);

    for(int i=0;i<lena;i++){
        if('a'<= *(pstr+i) && *(pstr+i)<= 'z'){
            *(prsta+rstcnt) = *(pstr+i) -N;
            rstcnt++;
        }
        else if('A'<= *(pstr+i) && *(pstr+i)<= 'z'){
            *(prsta+rstcnt) = *(pstr+i) + N;
            rstcnt++;
        }
        else if('0'<= *(pstr+i) && *(pstr+i)<= '9'){
            if('0'<= *(pstr+i+1) && *(pstr+i+1)<= '9'){
                num = 1;
                num *= (*(pstr+i)-48)*10;
                num += *(pstr+i+1)-48;
                // printf("num = %d\n",num);
                *(pstr+i+1) = '\n';
                for(int j=0;j<N;j++){
                    *(prsta+rstcnt) = num+64;
                    rstcnt ++;
                }
            }
            else{
                for(int j=0;j<N;j++){
                    *(prsta+rstcnt) = *(pstr+i)+16;
                    rstcnt ++;
                }
            }
        }
        else if(*(pstr+i)!='\n'){
            *(prsta+rstcnt) = ' ';
            rstcnt ++;
        }
    }
    *(prsta+rstcnt) = '\0';
    puts(rsta);

    

}
//CLikp5tGLE?Qej15J