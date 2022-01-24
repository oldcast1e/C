#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int check_row(int **p, int M, int N){//check_row함수 정의
    //2차원 배열의 주소 p, 2차원 배열의 행 수 M, 2차원 배열의 열 수 N
    int cnt=0,max = -1;
    for(int i=0;i<N;i++){//행 번 반복
        cnt = 0;
        for(int j=0;j<M;j++){//열 번 반복
            if(p[j][i]==0){ //열 행
                cnt++;//0이면 카운트 증가
                // printf("%d행 %d열 :[%d] | cnt = %d\n",j,i,p[j][i],cnt);
                if(cnt > max) max = cnt;//최대값 확인
            }
            else cnt = 0; //0카운트 초기화
        }
    }
    return max;
}
// p가 가리키는 M X N의 2차원 배열의 각 행을 검사하여 0이 연속해서 나타나는 횟수를 계산한다.
int check_col(int **p, int M, int N){
    //2차원 배열의 주소 p, 2차원 배열의 행 수 M, 2차원 배열의 열 수 N
    int cnt=0,max = -1;
    for(int i=0;i<M;i++){//열 번 반복
        cnt = 0;
        for(int j=0;j<N;j++){//행 번 반복
            if(p[i][j]==0){//열 행
                cnt++;//0이면 카운트 증가
                if(cnt>max) max = cnt;//최대값 확인
            }
            else cnt = 0; //0카운트 초기화
        }
    }
    return max;//반환
    
}
//p가 가리키는 M X N의 2차원 배열의 각 열을 검사하여 0이 연속해서 나타나는 횟수를 계산
int main(){

    int M,N;
    int x,y,z;//입력받을 정수 정의
    scanf("%d %d",&M,&N);//입력
    
    int **num = NULL;
    num = (int **)malloc(M*sizeof(int *));//M행 // 동적할당
    for(int i=0;i<M;i++) num[i] = (int *)malloc(N*sizeof(int));//N열//동적할당

    for(int i=0;i<M;i++)//행번
        for(int j=0;j<N;j++) num[i][j] = 0;//열번
    
    while(1){//000입력받을때까지 반복
        scanf("%d %d %d",&x,&y,&z);
        if(x == 0 && y == 0 && z == 0) break;
        num[x][y] = z;//해당 행렬에 저장
    }
    for(int i=0;i<M;i++){//
        for(int j=0;j<N;j++)printf(" %d",num[i][j]);//행렬 출력
        printf("\n");
    }//배열 출력
    int rst  = check_row(num,M,N)>check_col(num,M,N)?check_row(num,M,N):check_col(num,M,N);//최댓값 구하기
    printf("%d",rst);//출력
}

/*
3 5 
0 0 5 
0 1 15 
0 3 25 
1 2 35 
2 1 45 
2 3 55 
0 0 0

4 4
0 1 1
0 3 3 
1 0 1
1 2 3
2 2 0
2 3 6
3 1 2
0 0 0
*/