#include  <stdio.h>

void addArray(int *parra,int *parrb,int *prst,int size){
    //addArray함수 선언(세 개의 포인터와 크기 저장 변수를 인자로 가짐)
    for(int i=0;i<size;i++){//입력받은 size만큼 반복
        *(prst+i) = *(parra+i) + *(parrb+size-i-1);
        //결과값 배열에 역방향으로 더한 값을 저장함
        // printf("prst = %d| parra = %d (+) paarb = %d\n",*(prst+i),*(parra+i),*(parrb+size-i-1));
    } 

}
int main(){//메인함수
    int arra[20],arrb[20],rst[20]={0},n;//크기 20의 배열 3개 선언, 정수형 변수 선언
    int *parra = arra,*parrb = arrb,*prst = rst;//각각의 배열에 포인터 연결
    scanf("%d",&n);//정수를 입력받음
    for(int i=0;i<n;i++)scanf("%d",(parra+i));//n번 반복하여 문자를 입력받음
    for(int i=0;i<n;i++)scanf("%d",(parrb+i));//m번 반복하여 문자를 입력받음
    
    addArray(parra,parrb,prst,n);//함수 실행
    for(int i=0;i<n;i++)printf("%d ",*(prst+i));//결과값 출력
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
//N개의 정수를 두번 입력받아 (N<=20) 역방향으로 더하여 출력하는 프로그램을 작성하라

