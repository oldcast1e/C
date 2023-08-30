#include  <stdio.h>
int main(){
    
    int n,cnt=1,spn=0;
    scanf("%d",&n);
    
    for(int j=n;j>=1;j--){
        if(spn!=0)
            printf("\n");
        spn ++;
        for(int i=0;i<2*j-1;i++){
            printf("*");
        }
        
        cnt++;
    }
}
