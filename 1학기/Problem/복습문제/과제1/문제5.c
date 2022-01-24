#include  <stdio.h>
int main(){

    int n,max=-1;
    int cnt;
    scanf("%d",&n);
    cnt = n%10;
    max = (cnt>max?cnt:max);
    n/=10;

    cnt = n%10;
    max = (cnt>max?cnt:max);
    n/=10;

    cnt = n%10;
    max = (cnt>max?cnt:max);
    n/=10;

    printf("%d",max);


    
}