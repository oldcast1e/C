#include  <stdio.h>
int main(){
    
    int n,spn=0,cnt=0;
    scanf("%d",&n);


    for(int i=0;i<n;i++){
        if(spn!=0)
            printf("\n");
        spn++;
        for(int j=0;j<n;j++){
            if(i==j || j==(n-i-1))
                printf("X");
            else
                printf("O");
        }
    }
}
