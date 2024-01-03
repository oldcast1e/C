#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m;
    int ipt[100][100];
    int rst[100][100];
    //fgets(arr, 101, stdin);
    scanf("%d %d",&n,&m);
    //for(int i=0;i<cnt;i++)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)scanf("%d",&ipt[i][j]);
        // printf("\n"); cnt++;
    }
    int cnt;
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<m;j++) {
            cnt += ipt[i][j];
            ipt[i][j] = cnt;
        }
    }
    int cnt2;
    for(int i=0;i<m;i++){
        cnt2 = 0;
        for(int j=0;j<n;j++) {
            cnt2 += ipt[j][i];
            // printf("%d ",cnt2);
            rst[j][i] = cnt2;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%d ",rst[i][j]);
        printf("\n"); 
    }

    
} 
/*
1 2 3 4 5
5 4 3 2 1
1 5 2 4 3

1   2/3   3/6   4/10   5/15
>1    >3   >6     >10   >15                        
5   4/9   3/12   2/14   1/15
>6    >12    18     >24    >30   
1   5/6   2/8   4/12   3/15
>7   >18   >26   >36    >45         
1 3 6 10 15
6 12 18 24 30
7 18 26 36 45



1 3 6 10 15
+2 +3 +4 +5
6 12 18 24 30
+6 +6 +6 +6
7 18 26 36 45
 +9 +8 +10 +15
*/