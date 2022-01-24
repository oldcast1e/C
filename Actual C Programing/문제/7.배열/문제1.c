#include  <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    double sum=0,avg=0;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum += num[i];
    }
    avg = sum/n;
    for(int i=0;i<n;i++){
        if(num[i]>avg){
            printf("%d ",num[i]);
        }
    }

}
