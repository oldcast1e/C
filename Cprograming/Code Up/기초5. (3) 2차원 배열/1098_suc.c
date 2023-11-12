#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int w,h,n, l,d,x,y;
    int darr[100][100]={0};
    float n1,n2;

    scanf("%d %d",&w,&h);
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&l,&d,&x,&y);
        x -=1; y-=1;
        if(d==1){
            for(int j=0;j<l;j++){
                darr[x+j][y] = darr[x+j][y]==0?1:0;

            }
        }
        else if(d==0){
            for(int k=0;k<l;k++){
                darr[x][y+k] = darr[x][y+k]==0?1:0;
            }
        }
    }
    for(int i=0;i<w;i++){for(int j=0;j<h;j++) printf("%d ",darr[i][j]);printf("\n");}
} 