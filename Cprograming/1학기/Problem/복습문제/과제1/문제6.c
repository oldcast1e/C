#include  <stdio.h>
int main(){

    int n,m,k;
    int avg = 0;
    scanf("%d %d %d",&n,&m,&k);
    avg = (n>m && m>k || k>m && m>n ?m:avg);
    avg = (m>n && n>k || k>n && n>m ?n:avg);
    avg = (n>k && k>m || m>k && k>n ?k:avg);
    printf("%d",avg);

    
}