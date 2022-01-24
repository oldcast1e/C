#include  <stdio.h>
int main(){
    
    int sum=0;
    int num[100];
    for(int i=0;;i++){
        scanf("%d",&num[i]);
        if(i>1){
            

            for(int j=0;j<i;j++){
                for(int k=0;k<i;k++){

                    if(i!=k){
                        if(num[j]==num[k]){
                            for(int r=0;r<i-1;r++){
                                sum += num[r];
                            }
                            break;
                        }
                    }                 
                }
            }


        }
    }
    printf("%d",sum);

    
}
