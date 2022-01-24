#include  <stdio.h>
int mid(int *arr){//인자를 포인터로 받는 함수 mid선언
    int tmp;//값을 변환할 임의의 변수 선언
    if(*(arr)>*(arr+1)){//배열의 0번째 변수가 1번째 변수보다 큰 경우
        tmp = *(arr);*(arr) = *(arr+1); *(arr+1) = tmp;//두값을 바꿈
    }
    if(*(arr)>*(arr+2)){//배열의 번째 변수가 2번째 변수보다 큰 경우
        tmp = *(arr);*(arr) = *(arr+2); *(arr+2) = tmp;//두값을 바꿈
    }
    if(*(arr+1)>*(arr+2)){//배열의 1번째 변수가 2번째 변수보다 큰 경우
        tmp = *(arr+1);*(arr+1) = *(arr+2); *(arr+2) = tmp;//두값을 바꿈
    }
    //크기 3의 배열에서 중앙값을 출력하기위해선 최대 3번의 조건문으로 해결 가능

    return *(arr+1);//중앙값 반환
}
int main(){
    int arr[3];//크기 3의 배열 선언
    int *parr = arr;//배열의 포인터 선언
    for(int i=0;i<3;i++){//3번반복하여
        scanf("%d",(parr+i));//포인터를 이용하여 배열의 요소를 입력받음
    }
    printf("%d",mid(arr));//결과값 출력
}
