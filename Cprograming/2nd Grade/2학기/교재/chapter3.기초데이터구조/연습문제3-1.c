#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*----------------------생략-----------------------*/

// 3차원 배열 동적 생성 및 초기화 함수
int*** create3DArray(int x, int y, int z) {
    int*** array = (int***)malloc(x * sizeof(int**));  // 1차원 포인터 배열
    for (int i = 0; i < x; i++) {
        array[i] = (int**)malloc(y * sizeof(int*));  // 2차원 포인터 배열
        for (int j = 0; j < y; j++) {
            array[i][j] = (int*)malloc(z * sizeof(int));  // 3차원 정수 배열
        }
    }
    return array;
}

// 3차원 배열 요소에 랜덤 값 채우기
void fill3DArray(int*** array, int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                array[i][j][k] = rand() % 100;  // 0~99 사이의 값
            }
        }
    }
}

// 3차원 배열 출력 함수
void print3DArray(int*** array, int x, int y, int z) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
            }
        }
    }
}

// 3차원 배열 메모리 해제 함수
void free3DArray(int*** array, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(array[i][j]);  // 3차원 배열의 각 1차원 배열 해제
        }
        free(array[i]);  // 2차원 배열 해제
    }
    free(array);  // 1차원 배열 해제
}

int main() {
    srand(time(NULL));  // 난수 초기화

    // 각 차원의 크기를 랜덤으로 설정 (1~10)
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    int z = rand() % 10 + 1;

   

    // 3차원 배열 동적 생성
    int*** array = create3DArray(x, y, z);

    // 배열에 랜덤 값 채우기
    fill3DArray(array, x, y, z);

    int size_x,size_y,size_z;
    size_x = (int)sizeof(array);
    printf("size_x = %d",size_x); printf("\n");

    // 크기 출력
    printf("3차원 배열 크기: [%d][%d][%d]\n", x, y, z);

    // 배열 출력
    // print3DArray(array, x, y, z);

    // 메모리 해제
    free3DArray(array, x, y);

    return 0;
}
