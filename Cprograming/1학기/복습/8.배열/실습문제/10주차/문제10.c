#include  <stdio.h>
int main(){
    
    double N[10];
    for(int i=0;i<10;i++){
        scanf("%lf",&N[i]);
    }
    for(int i=0;i<10;i++){
        if(N[i]>0)
            printf("% .1f",N[i]);
    }

}


