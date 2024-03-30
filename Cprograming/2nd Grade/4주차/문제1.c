#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,a,b,tmp; 
    int num[101];

    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        for(int j=a;j<=(a+b)/2;j++){
            tmp = num[j];
            num[j] = num[b+a-j];
            num[b-j+a] = tmp;
        }
        
    }
    for(int i=0;i<n;i++)printf("%d ",num[i]); printf("\n");
}