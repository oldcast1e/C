#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,i=1,diagonal=1,val=1;
    int Arr[101][101] = {};

    scanf("%d %d", &n, &m);
    for(diagonal = 1;diagonal< n+m;diagonal++){//대각선의 횟수 만큼 반복!
        int temp_j = diagonal;//대각선 진행 순서 저장
        if(temp_j > m){ // m보다 큰 경우 = 최대 열 인덱스보다 큰 경우
            temp_j  = m;// 최대 인덱스는 m이므로 수정하고
            i++;//행을 내림
        }
        // printf("\n-------------- j = %d / temp_j = %d --------------\n",j,temp_j);
        int temp_i = i; // 행 번호 저장
        while(temp_j > 0){// 열 번호가 0보다 클 경우
            Arr[temp_i][temp_j] = val;
            // printf("Arr[%d][%d] = %d\n",temp_i,temp_j,val);
            val ++; // 저장하는 값 증가
            temp_j--; // 행 번호 감소
            temp_i++;// 열 번호 증가
            if(temp_i > n){break;} // 최대 행 번호가 n보다 큰 경우는 없음
        }
    }
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            printf("%d ",Arr[i][j]);
        }printf("\n");
     }
    

    
} 
/*

*/