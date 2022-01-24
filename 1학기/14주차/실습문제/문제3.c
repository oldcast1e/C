#include  <stdio.h>
int main(){
    
    int ar[50]={0}, N ;//크기 50의 배열과 정수N을 선언
    int *p ,cnt=0;//주소를 저장 p와 횟수를 저장할 cnt선언
    scanf("%d", &N);//정수를 입력받아
    for (p = ar; p < ar+N; p++) //N번 반복하여
        scanf("%d", p);//배열에 저장

    for (p = ar; p < ar+N; p++){//N번반복하여
        if(*p == 0) break;//해당 요소가 0이면 종료하고
        cnt ++;//아니면 횟수 증가
    }
    printf("%d",cnt);//결과값 출력
        
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

