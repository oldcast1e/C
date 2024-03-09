#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,i=1,j=1,cnt=1;
    int dnum[100][100]={0};

    scanf("%d %d",&n,&m); //이중 배열 입력
    
    for(j=1;j<n+m;j++){
        /*
        n,m을 입력할 시에 대각선의 개수는 n+m-1이다.
        만약 4 4입력 시에는 대각선의 개수는 7개이며 1,2,3,4,5,6,7 순이다.
        */
       int tmp_j = j;
       if(tmp_j > m) {tmp_j = m;i ++;}
       /*
       반복 인덱스를 저장한 tmp_j는 대각선 처리에서 j부터 시작한다.
       
       이때 j가 m을 넘길시에는 즉, 
       m보다 밖에서 대각선을 할 수 없으므로 한계를 m으로 정한다.
       */
       int tmp_i = i;
       while(tmp_j>0){
        /*
        대각선의 시작은 0행에서 일반적으로 시작하며
        마지막 열에 대각선이 쳐질 경우 행을 하나 증가한다.
        */
            dnum[tmp_i][tmp_j] = cnt; cnt++;
            // printf("[%d][%d] ",tmp_i,tmp_j);
            tmp_j--;
            tmp_i++;
            
            if(tmp_i > n){break;}
            /*
            위의 조건이 제일 중요한데, 행을 나타내는 tmp_i가 n보다 커지면 반복 종료한다.
            
            위의 반복은 열을 수로 돌아가므로 행은 열을 조건을 하는 반복이
            끝날때까지 행의 수는 증가되기 때문이다.
            */
       } printf("\n");

    }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)printf("%d ",dnum[i][j]);
        printf("\n"); 
    }
    

    
} 
/*

*/