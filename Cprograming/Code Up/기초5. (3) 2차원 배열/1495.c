#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,k,cnt=0;
    int d[1001][1001]={0};
    scanf("%d %d %d",&n,&m,&k);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    //for(int i=0;i<cnt;i++)
    int x1,x2,y1,y2,u;
    for(int i=0;i<k;i++){
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&u);
        d[x1][y1] = d[x1][y1]+u;
        d[x2+1][y2+1] = d[x2+1][y2+1]+u;
        d[x1][y2+1] = d[x1][y2+1]-u;
        d[x2+1][y1] = d[x2+1][y1]-u;
    }
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<m;j++){
            printf("%d ",d[i][j]);
            cnt += d[i][j];
            d[i][j] = cnt;
        }printf("\n");
    }printf("\n");

    // for(int i=0;i<n;i++){
    //     cnt = 0;
    //     for(int j=0;j<m;j++){
    //         cnt += d[i][j];
    //         d[i][j] = cnt;
    //     }
    // }
    
            
    for(int i=0;i<m;i++){
        cnt = 0;
        for(int j=0;j<n;j++){
            cnt += d[j][i];
            d[j][i] = cnt;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",d[i][j]);
        }printf("\n");
    }
    

    
} 
