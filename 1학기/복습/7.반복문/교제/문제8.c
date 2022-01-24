#include  <stdio.h>
int main(){
    
    int n,cnt=0,spn=0;
    scanf("%d",&n);

    for(int i=n;i>=1;i--){
        if(spn!=0)
            printf("\n");
        spn ++;

        for(int j=0;j<cnt;j++){
            printf(" ");
        }
        cnt++;
        for(int j=0;j<2*i-1;j++){
            printf("*");
        }
    }
}
