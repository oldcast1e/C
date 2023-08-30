#include  <stdio.h>
int main(){
    
    int n,num,cnt;
    
    int D[10];
    for(int i=0;i<10;i++){
        scanf("%d",&D[i]);
    }
    int max = D[0],min=D[0];
    for(int i=0;i<10;i++){
        if(D[i]>max)
            max = D[i];
        
        if(D[i]<min)
            min = D[i];
    }

    int x[max];
    for(int k=0;k<max;k++){
        x[k] = 0;
    }

    for(int i=min;i<max;i++){
        

    }

    for(int k=0;k<max;k++){
        printf("%d ",x[k]);
    }



}


