#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,i=1,j=1,cnt=1;
    int dnum[100][100]={0};

    scanf("%d %d",&n,&m); //이중 배열 입력
    
    for(j=1;j<n+m;j++){//대각선 개수 만큼
       int tmp_j = j;//대각선 임시 저장
       if(tmp_j > m) {tmp_j = m;i ++;}
       int tmp_i = i;
       while(tmp_j>0){
            dnum[tmp_i][tmp_j] = cnt; cnt++;
            tmp_j--;
            tmp_i++;
            if(tmp_i > n){break;}
       } printf("\n");

    }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)printf("%d ",dnum[i][j]);
        printf("\n"); 
    }
    

    
} 
/*

*/