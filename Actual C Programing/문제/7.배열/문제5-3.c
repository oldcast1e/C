#include  <stdio.h>
int main(){
    
    int num[100]={0,},sum=0;
    int N,key=0;
    for(int i=0;i<100;i++){

        scanf("%d",&num[i]);
        if(i==1){
            if(num[0]==num[1]){
                sum = num[1];
                key =1;
                break;
            }
        }
        else if(i>0){
            for(int j=0;j<i-1;j++){
            if(num[i]==num[j]){
                for(int k=0;k<i;k++){
                    sum += num[k];
                    // printf("%d ",num[k]);
                }
                key = 1;
                break;
            }
        }
       
        }
        if(key==1)
            break;
    }
    printf("%d",sum);
}
