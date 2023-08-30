#include  <stdio.h>
int main(){
    int N,n,sp=0;
    
    while(1){
        scanf("%d",&n);
        if(n==0||n==1 || n<0||n%3==0)
            break;
        int cnt = n-1;
        for(int i=1;i<=n;i++){
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
        printf("\n");
        cnt --;
    }
    }
}