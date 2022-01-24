#include  <stdio.h>
int main(){
    
    int n,cnt=1,stn=1,spn=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        if(spn!=0)
            printf("\n");
        spn++;
        for(int j=0;j<cnt;j++){
            printf("%d ",stn%10);
            stn++;
        }
        cnt++;
    }
}
