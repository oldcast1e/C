#include  <stdio.h>
int main(){
    
    int x[7]={0,};
    for(int i=0;i<7;i++){
        scanf("%d",&x[i]);
    }
    for(int i=0;i<7;i++){
        if(x[i]>=80){
            printf("%d %d\n",i,x[i]);
        }
    }
}


