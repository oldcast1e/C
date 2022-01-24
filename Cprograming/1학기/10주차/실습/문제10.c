#include  <stdio.h>
int main(){
    
    double num[10];//크기 10의 실수형 배열 선언
    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%lf",&num[i]);//실수를 입력받음
    }

    for(int i=0;i<10;i++){//10번 반복하여
        if(num[i]>0){//해당 요소의 값이 0보다 크면
            printf(" %.1lf",num[i]);//해당요소를 출력
        }
    }
    
    return 0;
}
