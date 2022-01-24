#include  <stdio.h>
int main(){
    
    double num[10],min;//크기 10의 실수형 배열 선언
    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%lf",&num[i]);//실수를 입력받음
    }
    min = num[0];//최솟값을 첫번째 배열 요소로 초기화
    for(int i=0;i<10;i++){//10번 반복하여
        if(num[i]<min)//배열의 요솟값이 min보다 작으면
            min = num[i];//min에 해당 배열 요솟값 대입
    }
    printf("%.1lf",min);//최솟값 출력
    
    return 0;
}
