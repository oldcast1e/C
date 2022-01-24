#include  <stdio.h>
int main(){
    
    int num[3],*pnum = num;//크기 3의 배열과 배열의 주소를 저장할 pnum선언
    int tmp,*j,cnt=0;//변환 위한 빈값 선언

    for(j=num;j<num+3;j++){//3번 반복
        scanf("%d",pnum+cnt);//배열에 저장
        cnt++;
    }

    for(int i=0;i<2;i++){//2번 반복
        if(*(pnum+i)>=*(pnum+i+1)){//좌측 수가 우측수보다 크거나 같으면
            tmp = *(pnum+i);//빈값에 i번ㅂ째 숫자 저장
            *(pnum+i) = *(pnum+i+1);//i번째 숫자에 i+1번째 숫자 저장
            *(pnum+i+1)  = tmp; //i+1번ㅂ째에 빈값에 있는 값을 저장
        }
    }
    printf("%d",*(pnum+1));//결과값 출력

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

