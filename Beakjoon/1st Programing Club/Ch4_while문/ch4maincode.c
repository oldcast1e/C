#include  <stdio.h>

int main(){

    int n,m,rst;
    int cnt=0;
    scanf("%d",&n);
    
    if(10>n) n*=10;
    m = n;
    while (1)
    {
        rst = m%10*10 +((m/10)+(m%10))%10;
        m = rst;
        //printf("%d\n",rst);
        //26 -> 2+6=8 -> 60+8%10
        //68 -> 6+8=14 -> 80+14%10
        cnt ++;
        if(rst == n) break;
    }
    printf("%d",cnt);
}