#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10
#define SIZE 100

void generateUniqueRandomNumbers(int array[ROWS][COLS]) {
    int numbers[1000];
    
    // 1부터 1000까지의 숫자를 배열에 저장
    for (int i = 0; i < 1000; i++) {
        numbers[i] = i + 1;
    }
    
    // 난수를 초기화
    srand(time(NULL));
    
    // Fisher-Yates shuffle 알고리즘으로 배열을 무작위로 섞음
    for (int i = 999; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
    // 10x10 배열에 무작위로 섞인 숫자 중 처음 100개를 채움
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = numbers[i * COLS + j];
        }
    }
}

// N x N 정사각 배열

int findRow(int *A, int x){
    //열 순회
    int i = 0;
    while(i < sizeof(*A)/sizeof(x)){
        if( x == A[i]) return i;
        else i = i + 1;
    }
    return -1;
}

void findMatrix(int **A, int x){
    //행 순회
    int r = 0;
    while(r < sizeof(**A)/sizeof(x)){
        int i = findRow(A[r],x);
        if(i != -1){
            printf("find at %d in row(%d)/cal(%d)",x,i,r);
            return ;
        }
        else r ++;
    }
}

int main(){
    int array[ROWS][COLS];
    
    generateUniqueRandomNumbers(array);
    findMatrix(array,55);
} 