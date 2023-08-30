#include  <stdio.h>

int arrsum(int *S,int *E){//함수 정의

    int rst=0;//결과값(요소의 합)
    int *p;//임의의 포인터 선언
    for(p=S;p<E;p++){//포인터가 함수의 인자1부터 인자2까지 진행
        rst += *p;//결과값에 더함
        //printf("<%d>\n",rst);
    }
    return rst;//결과값 반환
}
int main(){//메인 함수
    
    int N,S,E;//3개의 변수 선언
    int num[100];//크기가 100인 배열 선언

    int *pn;//포인터 선언
    
    scanf("%d %d %d",&N,&S,&E);//3개의 정수를 입력받음
    for(pn=num;pn<num+N;pn++){//N만큼 포인터을 올려가며
        scanf("%d",pn);//포인터를 입력받음
        //=이는 num이라는 배열의 주소를 지작으로 N번 반복하여 배열에 저장하는 것과 같음
    }
    int *ps = num+S,*pe = num+E+1;//ps:배열의 시작점=num주소 +S,pe:배열의 마지막 주소=num의 주소 + E +1(그전까지 수행)
    printf("%d",arrsum(ps,pe));//함수 실행 후 결과값 출력



}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

