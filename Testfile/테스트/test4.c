#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// int findRow(int A[], int n, int x);
// // n*n 크기의 배열에서 값 x를 찾는 함수
// int findMatrix(int **A, int n, int x) {
//   int r = 0; // 행 인덱스
//   int i; // 열 인덱스

//   // 모든 행을 반복
//   while (r < n) {
//     // 각 행에서 findRow 함수를 사용하여 x 값을 찾는다
//     printf("findMatrix 실행 중...\n");
//     // i = findRow(A[r], n, x);

//     // // x 값을 찾았다면
//     // if (i >= 0) {
//     //   // 위치를 출력하고 함수를 종료한다
//     //   printf("found at %d, %d\n", r, i);
//     //   return 1;
//     // }

//     // 다음 행으로 이동한다
//     r++;
//   }

//   // x 값을 찾지 못했다면
//   printf("not found\n");
//   return 0;
// }

// // 배열 A[row]에서 값 x를 찾는 함수
// int findRow(int A[], int n, int x) {
//   int l = 0; // 왼쪽 인덱스
//   int r = n - 1; // 오른쪽 인덱스
//   int m; // 중간 인덱스

//   // 이진 탐색을 사용하여 x 값을 찾는다
//   while (l <= r) {
//     m = (l + r) / 2;

//     // x 값을 찾았다면
//     if (A[m] == x) {
//       return m;
//     }

//     // x 값이 m보다 크다면
//     else if (A[m] < x) {
//       l = m + 1;
//     }

//     // x 값이 m보다 작다면
//     else {
//       r = m - 1;
//     }
//   }

//   // x 값을 찾지 못했다면
//   return -1;
// }
int cnt = 1;
int main(){
    int dnum[100][100];
    // int **dnum = (int **)malloc(sizeof(int*) * 101);
    // for(int i=0;i<10;i++) *dnum = (int *)malloc(sizeof(int)*110);
    
    for(int i=0;i<10;i++){
        // printf("-");
        for(int j=0;j<10;j++){
            dnum[i][j] = cnt; 
            cnt++;
            printf("%d ",dnum[i][j]);
        }
    }
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++)printf("%d ",dnum[i][j]);
    //     printf("\n"); 
    // }
    // for(int i=0;i<10;i++)findMatrix(dnum, 10, 65);
}