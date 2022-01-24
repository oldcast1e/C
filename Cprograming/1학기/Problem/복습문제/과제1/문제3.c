#include  <stdio.h>
int main(){

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    printf(n/100==m/100 && m/100==k/100?"T":(n/100!=m/100 && n/100!=k/100&& m/100 !=k/100?"S":"D"));

    
}