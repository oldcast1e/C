#include  <stdio.h>
int main(){
    
    int n,cnt=1,spn=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        if(spn!=0)
            printf("\n");
        spn++;
        for(int j=cnt;j<=n;j++){
            printf("%d",j);
        }
        for(int j=1;j<cnt;j++){
            printf("%d",j);
        }
        cnt++;
        

    }
}
