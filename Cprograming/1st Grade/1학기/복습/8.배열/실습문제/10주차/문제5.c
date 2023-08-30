#include  <stdio.h>
int main(){
    
    int X[10];
    for(int i=0;i<10;i++){
        scanf("%d",&X[i]);
    }
    int max = X[0];
    for(int i=0;i<10;i++){
        if(X[i]>max)
            max = X[i];
    }
    printf("%d",max);
}


