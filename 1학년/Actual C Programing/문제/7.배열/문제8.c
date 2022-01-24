#include  <stdio.h>
int main(){
    
    int n[5],tmp;
    for(int i=0;i<5;i++){
        scanf("%d",&n[i]);
    }

    for(int i=0;i<5;i++){
        if(n[i]>n[i+1]){
            tmp = n[i];
            n[i] = n[i+1];
            n[i+1] = tmp; 
        }
    }

    for(int i=0;i<5;i++){
       printf("%d ",n[i]);
    }
}
