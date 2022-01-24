#include  <stdio.h>
char arra[6],arrb[6];//입력받을 배열과 출력할 배열 선언
char *parra = arra,*parrb = arrb;//각각의 배열을 포인터에 연결
void strcopy(){//strcopy함수 선언
    for(int i=0;i<6;i++)*(arra+i) = *(arrb+i);//반복문을 이용하여 문자열 b에 있는 문자들을 a에 저장
}
int main(){//메인함수
    for(int i=0;i<6;i++){//6번 반복하여 
        scanf("%c",(parrb+i));//문자를 입력받고
    }
    strcopy();//함수를 실행
    for(int i=0;i<6;i++){//6번반복하여
        printf("%c",*(parra+i));//복사한 문자를 출력
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//포인터를 이용하여 문자 6개를 복사하는 함수를 만들고 출력하라

