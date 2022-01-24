#include  <stdio.h>
int main(){
    
    int n,cnt=1,spn=0,stn=1;
    scanf("%d",&n);
    int rsn = n;
    
    while (n>=stn)
    {

        if(spn!=0)
            printf("\n");
        spn++;
        for(int i=stn;i<=rsn;i++){
            printf("%d",i%10);
        }
        stn++;
        rsn++;
    }
    
}
