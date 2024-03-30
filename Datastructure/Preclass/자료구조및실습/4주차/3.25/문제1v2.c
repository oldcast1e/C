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
/*
10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4

-9 33 9 81 3 36 0 12 91 10

6
30 10 20 0 40 50
2
1 2 0 3

0 10 20 30 40 50
*/