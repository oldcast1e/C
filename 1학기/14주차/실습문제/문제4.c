#include  <stdio.h>
int main(){
    
    int num[3];//정수형 배열 선언
    int *p,tmp;//포인터 변수와 빈 변수 선언

    for(p=num;p<num+3;p++)//3번 반복하여
        scanf("%d",p);//해당 포인터의 요소에 저장

    // for(p=num;p<num+3;p++)
    //     printf("%d ",*p);
        
    for(p=num;p<num+2;p++){//2번 반복하여
        if(*p>=*(p+1)){//해당 포인터에서 좌>우이면
            tmp = *p;//빈 값에 좌측값 저장
            *(p) = *(p+1);//좌측값에 우측값 저장
            *(p+1) = tmp;//우측값에 빈 값(저장했던)대입
        }
    }

    if(*(p-2)>*(p-1)){//배열에서 첫번째와 두번째 숫자 비교
        tmp = *(p-1);//첫번째 숫자를 빈값에 저장
        *(p-1) = *(p-2);//두번째숫자를 첫번째 숫자에 대입
        *(p-2) = tmp;//두번째 숫자 변환
    }
    printf("%d",*(p-1));//결과값 출력(사이값은 배열에서 가운데 값)
      

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

