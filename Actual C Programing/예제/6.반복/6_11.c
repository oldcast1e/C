#include  <stdio.h>
int main() 
{
    int e =0,o=0;
    for(int a=2;a<=10;a+=2){
        e+=a;
    }
    for(int b=1;b<=10;b+=1){
        o+=b;
    }
    printf("%d %d",e,o);

}