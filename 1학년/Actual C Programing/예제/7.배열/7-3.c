#include  <stdio.h>
int main(){
    
    int X[10],Y[10],Z[10];
    for(int i=0;i<10;i++){
        scanf("%d",&X[i]);
    }
    for(int i=0;i<10;i++){
        scanf("%d",&Y[i]);
    }

    for(int i=0;i<10;i++){
        Z[i] = X[i]+Y[9-i];
    }

    for(int i=0;i<10;i++){
       printf("%d ",Z[i]);
    }
}
