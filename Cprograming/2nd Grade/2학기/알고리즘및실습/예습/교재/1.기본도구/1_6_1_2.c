#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SIZE 100

void generateUniqueRandomNumbers(int array[ROWS][COLS]) {
    int numbers[100];
    
    // 1부터 100까지의 숫자를 배열에 저장
    for (int i = 0; i < 100; i++) {
        numbers[i] = i + 1;
    }
    
    // 난수를 초기화
    srand(time(NULL));
    
    // Fisher-Yates shuffle 알고리즘으로 배열을 무작위로 섞음
    for (int i = 99; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
    // 10x10 배열에 무작위로 섞인 숫자 중 처음 100개를 채움
    for (int i = 0; i < ROWS; i++) {// 행 만큼 반복
        for (int j = 0; j < COLS; j++) { // 열 만큼 반복
            array[i][j] = numbers[i * COLS + j];
            /*
            array는 2차원 배열
            numbers는 1차원 배열 
                -> numbers에서는 1부터 100까지의 숫자가 랜덤으로 섞여있음
            1) i = 0 일때, 0+0, 0+1 ,,, 0+9
            2) i = 1 일때, 1+10, 1+11 ,,, 1+19
            ,
            ,
            ,

            결국 1차원 배열을 2차원에 저장하는 알고리즘임.
            */
        }
    }
}

void findMatrix(int array[ROWS][COLS], int x) {
    // 행 순회
    for (int r = 0; r < ROWS; r++) {
        // 열 순회
        for (int c = 0; c < COLS; c++) {
            if (array[r][c] == x) {
                printf("Found %d at row %d, column %d\n", x, r, c);
                return;
            }
        }
    }
    printf("%d not found in the matrix.\n", x);
}

int main() {
    int array[ROWS][COLS];
    
    generateUniqueRandomNumbers(array);
    
    // 배열의 내용을 출력
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
    
    // 배열에서 숫자 55를 찾기
    findMatrix(array, 55);
    
    return 0;
}
