#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //순환문이용
    int n,m,a,b,tmp; 
    int num[100];

    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    scanf("%d",&m);
    

    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        for(int j=a;j<=(a+b)/2;j++){
            tmp = num[j];
            num[j] = num[b+a-j];
            num[b-j+a] = tmp;

            for(int k=0;k<n;k++)printf("%d ",num[k]); printf("\n");
        }
        // for(int i=0;i<n;i++)printf("%d ",num[i]); printf("\n");
    }
    // for(int i=0;i<n;i++)printf(" %d",num[i]);
} 
/*
10
3 81 9 12 0 -9 36 91 10
3
3 7 4 5 0 4

*/