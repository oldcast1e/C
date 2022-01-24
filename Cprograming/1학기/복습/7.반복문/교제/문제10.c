#include  <stdio.h>
int main(){
    
    int n,num=1,cnt=1,spn=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        if(spn!=0)
            printf("\n");
        spn++;
        for(int j=0;j<cnt;j++){
            printf("%d ",num);
            num++;
        }

        cnt++;
    }

}
