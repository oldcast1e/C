#include  <stdio.h>
int main(){
    
    int num[10][10];
    int n,tmp,spn=0,cnt;
    scanf("%d",&n);
    if(n%2==0)
        cnt = n/2;
    else
        cnt = (n-1)/2;


    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            scanf("%d",&num[j][i]);
    }
    }

    for(int i=0;i<cnt;i++){
        tmp = num[i][i];
        num[i][i]= num[n-i-1][n-i-1];
        num[n-i-1][n-i-1]= tmp;
    }

    for(int i=0;i<cnt;i++){
        tmp = num[i][n-i-1];
        num[i][n-i-1]= num[n-i-1][i];
        num[n-i-1][i]= tmp;
    }



    for(int j=0;j<n;j++){
        if(spn!=0)
            printf("\n");
        spn++;

        for(int i=0;i<n;i++){
            printf("%d ",num[j][i]);
        }
        
    }

}
