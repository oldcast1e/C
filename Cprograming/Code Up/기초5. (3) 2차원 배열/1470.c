#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,n,m,cnt=1;
    int dnum[1000][1000];

    scanf("%d",&a);
    for(int i=0;i<a;i++){
        cnt = i+1;
        for(int j=0;j<a;j++) {dnum[i][j] = cnt;cnt+=a;}
    }

    for(int i=0;i<a;i++){
        if(i%2==0) cnt = i;
        else cnt = a-1-i;
        for(int j=0;j<a;j++){ 
            printf("%d ",dnum[j][i]);
        }
    }
}

/*
1 2 3
4 5 6
7 8 9 (x)

1 4 7 
2 5 8
3 6 9 (0)

1 6 7
2 5 8
3 4 9

1 10 11 20 21
2 9 12 19 22
3 8 13 18 23
4 7 14 17 24
5 6 15 16 25


*/