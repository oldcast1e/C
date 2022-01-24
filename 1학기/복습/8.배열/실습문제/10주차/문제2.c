#include  <stdio.h>
int main(){
    
    int N[10],sum = 0;
    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
        sum += N[i];

    }
    printf("%d",sum);
}


