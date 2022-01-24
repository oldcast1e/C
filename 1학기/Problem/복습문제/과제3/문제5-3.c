#include  <stdio.h>
int main(){

    int n,even=0,odd=0;
    scanf("%d",&n);
    while(n>0){
        if(n%2==0){
            even +=n%10;
            even *=10;
            n/=10;
        }
        else{
            odd +=n%10;
            odd *=10;
            n/=10;
        }
    
    }
    printf("%d %d",even/10,odd/10);



}