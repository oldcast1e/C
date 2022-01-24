#include  <stdio.h>
int main(){
    
    int D[5],tmp,cnt=0;//5크기의 배열과 변환변수, 카운트 변수 선언
    for(int i=0;i<5;i++){//5번 반복 시
        scanf("%d",&D[i]);//배열의 요소를 입력받음
    }
    for(int i=0;i<4;i++){//4번 반복 시(5는 포함 안되야 함)
        
        if(D[i]>D[i+1]){//배열의 요소가 그 다음 요소보다 큰 경우
            tmp = D[i];//변환값에 저장 후
            D[i] = D[i+1];
            D[i+1] = tmp;//순서를 바꿈
        }
        
    }
    for(int i=0;i<5;i++){//5번 반복시
        if(cnt!=0){
            printf("\n");//첫번째 줄 빼고 앞줄을 띄움
        }
        cnt ++;
        printf("%d ",D[i]);//결과값 출력
    }

    
    
}
