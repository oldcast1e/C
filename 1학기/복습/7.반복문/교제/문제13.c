#include  <stdio.h>
int main(){
    
    int n,spn=0;
    scanf("%d",&n);

    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                if((i+j+k)==n){
                    if(spn!=0)
                        printf("\n");
                    spn++;
                    printf("%d %d %d",i,j,k);
                }
                    
            }
        }
    }
}
