#include  <stdio.h>
int main(){
    
    int D[9]={0,};
    for(int i=1;i<=9;i++){
        D[i-1] = 3*i;
        printf("%d",D[i-1]);
    }
}


