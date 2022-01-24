#include  <stdio.h>
int main(){
    
    char U[5],tmp;//입력받을 크기 5의 char형 배열 선언, 변환할 빈 값 변수 선언
    int cnt = 0;//줄 띄움 변수
    for(int i=0;i<5;i++){//5번 반복하여
        scanf("%c",&U[i]);//배열에 차례대로 입력
    }
    for(int j=0;j<5;j++){//5번 반복하여
        if(cnt!=0)//cnt가 0이 아니면
            printf("\n");//줄을 띄우고(0일때는 안띄움 = 첫번째 반복때는 줄 안띄움)
        cnt++;//cnt를 증가

        for(int k=0;k<5;k++){//5번 반복하여
            printf("%c",U[k]);//배열의 요소 전체 출력
        }
        for(int i=4;i>=0;i--){//5번 반복하여
            if(i==4) tmp = U[i];//배열의 마지막 요소를 tmp로 저장하고

            if(i!=0) U[i] = U[i-1];//뒷 요소를 앞의 요소에 저장
            else U[i] = tmp;//맨 첫번째 요소를 맨 마지막 요소로 저장
        }
        
        
    }
    return 0;

}