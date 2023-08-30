#include <stdio.h>
#include <stdlib.h>
void add(int*, int**);

int main(void){
    int size = 5;
    int* num = (int*)malloc(sizeof(int)*size); //길이가 5인 배열 생성
    int i = 0;
    //-1이 입력될 때 까지 무한루프
    while (1){
        scanf("%d", &num[i]);
        //사용자 입력값이 -1이면 반복문 탈출
        if (num[i] == -1) break;
        //i+1번째가 size와 같으면 add함수를 호출
        if (i + 1 == size) add(&size, &num);
        i++;
    }
    for (int j = 0; j < i+1; j++)
        printf(" %d",num[j]);
    free(num);
    return 0;
}


void add(int* s, int** ar){//배열크기 증가 함수 정의
     int update = *s + 3; //size의 크기를 3 증가시킴
     int* temp = (int*)malloc(sizeof(int)*update);
     //크기 증가한 동적할당

     for (int i = 0; i < *s; i++)
          temp[i] = (*ar)[i];//저장
     free(*ar); //이전 배열 삭제

     *ar = temp;
     *s += 3; //main의 size를 3증가시킴
}



