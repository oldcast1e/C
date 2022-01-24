#include  <stdio.h>
int main(){
    
    int n[5],tmp,cnt=0;
    for(int i=0;i<5;i++){
        scanf("%d",&n[i]);
    }

    for(int j=0;j<4;j++){

        for(int i=0;i<5;i++){
        if(n[i]>n[i+1]){
            tmp = n[i];
            n[i] = n[i+1];
            n[i+1] = tmp; 
        }
    }
    if(cnt!=0)
        printf("\n");
    cnt++;
    for(int i=0;i<5;i++){
       printf("%d ",n[i]);
    }
    }
}
