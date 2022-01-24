#include  <stdio.h>
int main(){

    int n[5],max;
    for(int i=0;i<5;i++){
        scanf("%d",&n[i]);
    }
    max = n[0];
    for(int i=1;i<5;i++){
        if(max<n[i])
            max = n[i];
    }
    printf("%d",max);

}
