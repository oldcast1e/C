#include  <stdio.h>
int main(){
    int n,sp=0;
    scanf("%d",&n);
    int cnt = n-1;
    for(int i=1;i<=n;i++){
        if(sp!=0){
            printf("\n");
        }
        sp++;
        for(int k = cnt;k>=1;k--){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            
            if(i!=n){
                if(j==1 || j==2*i-1){
                    printf("X");
            }
                else 
                    printf("O");
            }
            else{
                printf("X");
            }
        }
        cnt --;
    }
}