#include  <stdio.h>

void strcopy(char a[],char b[]){//strcopy함수 정의

    char *p1 = a, *p2  = b;//a,b포인터 선언
    for(int i=0;i<6;i++){//6번 반복
        *(p1+i) = *(p2+i);//b포인터 요소를 a포인터 요소에 대입
    }
}

int main(){//메인 함수 선언
   
    char a[6],b[6];//두 개의 배열 선언
    char *p1 = a, *p2=b;//포인터 선언
    for(int i=0;i<6;i++){//6번 반복
        scanf("%c",(p2+i));//b의 포인터 요소에 저장
    }
    strcopy(a,b);//함수 실행

    for(int i=0;i<6;i++){//6번 반복
        printf("%c",*(p1+i));//결과출력
    }

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

