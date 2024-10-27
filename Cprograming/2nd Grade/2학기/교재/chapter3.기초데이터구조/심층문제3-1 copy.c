#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d",&n);
    int cnt = 1;

    int **num = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) num[i] = (int*)malloc(sizeof(int)*n);

    // for(int i=0;i<n;i++)for(int j=0;j<n;j++)  num[i][j] =0;
    
    int up = 0,down = n-1,left=0,right=n-1;

    while(n*n >= cnt){
        for(int i=left ; i <= right; i++){num[up][i] = cnt ++;} up ++;
        for(int i = up; i<=down;i++){num[i][right] = cnt++;} right --;
        for(int i = right; i>= left;i--){ num[down][i] = cnt++;} down --;
        for(int i = down; i >= up ;i--){ num[i][left] = cnt++;} left++;
    }
    
    for(int i=0;i<n;i++){for(int j=0;j<n;j++) printf("%2d ",num[i][j]);printf("\n");}
 
}