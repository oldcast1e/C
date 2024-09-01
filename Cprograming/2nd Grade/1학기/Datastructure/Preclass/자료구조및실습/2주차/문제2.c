#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mostOnes(int **dnum, int num){
    int *index = (int*)malloc(sizeof(int)*num);
    // for(int i=0;i<num;i++)index[i] = 101;

    int i=0,j=0,min = 101,cnt=0,max=-1;
    while(num-1 >= i){
        if(dnum[i][j]==1) {if(j==num-1)return(i); 
            printf("[1] i = %d | j = %d \n",i,j);
            // key = 0;
            index[cnt] = i; cnt ++;
            j++;
        }
        else if(dnum[i][j]==0){
            printf("[0] i = %d | j = %d \n",i,j);
            // if(dnum[i][j-1]!=0 && key) index = i; 
            // index[cnt] = i; cnt ++;
            // index = index < i ? i : index;
            i++;
        }
    }
    for(int i=0;i<num;i++)printf("%d ",index[i]); printf("\n");

    // printf(">>cnt = %d\n",cnt);
    for(int i=0;i<cnt;i++){
        if(min > index[i] && index[i]!=0) min = index[i];
    }
    return min;
}
int main(){
    int num;scanf("%d",&num);
    int **dnum = (int**)malloc(sizeof(int*)*num);
    for(int i=0;i<num;i++) dnum[i] = (int*)malloc(sizeof(int)*num);

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)scanf("%d",&dnum[i][j]);
    }
    int rst= mostOnes(dnum,num);
    printf("rst = %d",rst);
  
    

    
} 
/*

*/
/*
[ 문제 2 ] 비트행렬에서 최대 1행 찾기
n × n 비트 행렬 A의 각 행은 1과 0으로만 구성되며, A의 어느 행에서나 1들은 해당 행의 0들보다 앞서 나온다고 가정하자. 
행렬 A를 입력받아, 가장 많은 1을 포함하는 행을 찾는 프로그램을 작성하시오. 

그러한 행이 여러 개 있을 경우 
그 가운데 가장 작은 행 번호를 찾아야

8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0

1->1->1->1->0  0  0  0
1  1  1  1  1->0  0  0
1  0  0  0  0  0  0  0
1  1  1  1  1  1  0  0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/