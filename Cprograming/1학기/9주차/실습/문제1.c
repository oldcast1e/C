#include  <stdio.h>
int main(){
    
    int n,cnt=0,total=0;//정수형 변수 n과 total을 선언+ 줄띄울 변수 cnt
    double avg=0;//실수형 변수(평균) 선언
    int D[5]={0,};//5개의 배열을 만듦
    
    for(int i=0;i<5;i++){//5번 반복
        scanf("%d",&n);
        D[i]= n;//정수를 입력받고 이를 배열에 저장함
        total += i;//평균값을 만들기 위해 total 변수에 값 더함
    }
    avg = (double)total/5;//평균
    for(int j=0;j<5;j++){//평균과 비교하는 반복
        if(D[j]>avg){//배열에 저장된 값이 평균보다 큰 경우
            if(cnt!=0){//cnt가 0이 아니면(첫번째 안띠움)
                printf("\n");//줄 띄움
            }
            cnt++;//cnt를 1올림
            printf("%d",D[j]);//값을 출력
        }
    }

}


