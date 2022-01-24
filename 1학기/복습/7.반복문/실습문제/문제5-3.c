#include  <stdio.h>
int main(){
    
    int n,cnt=1,spn=0;
    scanf("%d",&n);
    
    for(int j=0;j<n;j++){
        if(spn!=0)
            printf("\n");
        spn ++;
        for(int i=0;i<2*cnt-1;i++){
            printf("*");
        }
        
        cnt++;
    }
}
