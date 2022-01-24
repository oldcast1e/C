#include  <stdio.h>

int add_to_k(int *num, int *dp2){//add_to_k함수 정의

    int rst=0,*p;//합을 저장할 지역변수와 임의의 포인터 선언
    for(p =num;p<dp2+1;p++){//첫번째 인자(배열의 시작점)부터 두번째 인자(dp2)만큼 반복
        //printf("<%d>",*p);
        rst += *p;//결과값(지역변수)에 저장
    }
    return rst;//결과값 반환
}

int main(){//메인함수
    
    int N;//반복횟수 변수 선언
    int rst = 0,*dp1,*dp2;//최종 결과값을 0으로 초기화 및 두개의 포인터 선언

    int d[100];//크기 100의 포인터 선언
    scanf("%d",&N);//반복횟수를 입력받고

    for(dp1 =d;dp1<d+N;dp1++){//반복횟수 만큼 반복하여
        scanf("%d",dp1);//배열에 차례로 저장
    }
    
    for(dp2 =d;dp2<d+N;dp2++){//dp2 = num의 시작점 부터 마지막까지 반복
        rst += add_to_k(d,dp2);//함수 실행 후 결과값(최종)에 저장
        //printf("\n");
    }
    printf("%d",rst);//결과 출력
    



    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

