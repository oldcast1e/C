#include  <stdio.h>
int main(){

    char u;
    int a=0,b=0,numsum=0,el=0;
    while(1){

        scanf("%c",&u);
        if(u == '*')
            break;


        if('A'<=u && u<='Z'){
            a +=1;
        }
        else if ('a'<=u && u<='z'){
            b +=1;
        }
        else if('0'<=u && u<='9'){
            numsum +=u-48;
        }
        else
            el +=1;

    }
    printf("%d %d %d %d",a,b,numsum,el);
}
