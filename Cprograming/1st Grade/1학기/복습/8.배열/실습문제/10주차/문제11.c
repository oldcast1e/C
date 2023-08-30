#include  <stdio.h>
int main(){
    
    double N[10];
    for(int i=0;i<10;i++){
        scanf("%lf",&N[i]);
    }
    double min =  N[0];
    for(int i=0;i<10;i++){
        if(N[i]<min)
            min = N[i];
    }
    printf("%.1f",min);

}


