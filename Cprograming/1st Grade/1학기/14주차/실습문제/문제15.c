#include  <stdio.h>

void ABC(int *s,int e){//ABC함수 정의
    //printf("<%d>",e);
    int *sc;//임의의 포인터 선언
    int max = *s,*rst,tmp;//지역변수)최댓값 초기화
    //max값의 최종값의 위치를 저장할 rst포인터와 변환시 사용할 빈 값 tmp 선언
    for(sc=s;sc<s+e;sc++){//함수의 인자1부터 인자2까지 반복
        if(*sc >= max){//해당 요소가 max보다 큰 경우
            max = *sc;//max에 저장하고
            rst = sc;//해당 위치를 rst에 저장
        }
    }
    // printf("%d %d\n",*rst,*s);
    tmp = *rst;//rst값을 tmp에 저장
    *rst = *s;//첫번째 값을 rst위치에 저장
    *s = tmp;//첫번째 값에 tmp 저장

    // return 0;

    //변환됨

}
int main(){//메인 함수
    
    int num[10];//크기 10의 배열 선언
    int *pn,e=10;//임의의 포인터 선언

    for(pn=num;pn<num+10;pn++){//10번 반복하여
        scanf("%d",pn);//포인터를 이용해 배열에 요소값 저장
    }

    for(pn=num;pn<num+10;pn++){//배열의 시작점부터 배열의 (시작점+10)의 위치까지
        ABC(pn,e);//pn부터 배열의 마지막 항까지 함수 실행
        e--;
    }


    for(pn=num;pn<num+10;pn++){//10번 반복하여
        printf(" %d",*pn);//순서대로 출력
    }

    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

