#include  <stdio.h>
int main(){
    
    int N,cnt=0;
    int X[10];
    scanf("%d",&N);
    while(N>0){
        X[cnt] = N%10;
        N/=10;
        cnt++;
    }
    for(int i=0;i<=cnt-1;i++){
        printf(" %d",X[i]);
    }

    

}


