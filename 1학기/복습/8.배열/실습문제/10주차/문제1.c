#include  <stdio.h>
int main(){
    
    int N[10],spn=0;
    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);

    }
    for(int i=0;i<10;i++){
        if(N[i]%2==0)
            printf(" %d",N[i]);
    }

}


