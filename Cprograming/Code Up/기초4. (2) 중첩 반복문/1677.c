#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){//세로
        for(int j=0;j<n;j++){
            cnt =0;
            if(i==0 || i==m-1){
                if(j==0 || j == n-1)printf("+");
                else printf("-");
            }
            else if (j==0 || j== n-1 ){printf("|");cnt=1;}
			
					if(cnt == 1)for(int k=0;k<n-2;k++){printf(" ");cnt=0;}
        }printf("\n");
    }
} 
/*
4 3
+--+
|  |
+--+
*/