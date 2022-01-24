#include  <stdio.h>
int main(){
    
    int num[100],sum=0;
    for(int i=0;;i++){

        scanf("%d",&num[i]);
        printf("%d",i);
        for(int j=0;j<i-1;j++){
            if(num[i]==num[j]){
                for(int k=0;k<i-1;k++){
                    sum += num[k];
                }
                break;
            }
        }
    }
}
