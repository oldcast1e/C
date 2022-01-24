#include  <stdio.h>
int passengerN(int N){//passengerN 함수
    int psgnum;//승객의 수가 충분한지의 여부를 나타내는 변수 psgnum선언
    if(N>=5) psgnum = 0;//5보다 큰경우(충분한 경우) 0을 저장
    else psgnum = -1;//아닌 경우 -1저장

    return psgnum;//충분여부 변수 반환
}
int changesseat(int *ar){//changesseat함수 선언
    int rst=0,tmp[21],*ptmp = tmp;//결과를 저장할 변수 rst와 크기 21의 배열 선언 및 포인터 연결
    for(int k=1;k<=21;k++) *(ptmp+k-1) = k;//tmp배열 초기화 ->1,2,3,4,5,6,,,,

    for(int i=0;i<21;i++){//21번 반복하여(1)
        for(int j=0;j<21;j++){//21번 반복하여(2)
            if(*(tmp+i)==*(ar+j)) *(tmp+i) = 0;//tmp배열의 요소와 ar의 요소가 겹치는게 있으면 해당 tmp요소값을 0으로 바꿈
            // -> 중복된 수를 0으로 바꿈으로서 나중에 예약이 안된 수를 찾기 쉽게함
        }
    }//tmp배열과 입력받음 arr배열이 같으면 해당 tmp요소의 값을 0으로 바꿈
    for(int i=0;i<21;i++){//21번 반복하여
        if(*(tmp+i)!=0){//tmp의 요소가 0이 아닌경우 = 중복되지 않은 수인경우
            rst = *(tmp+i);//결과값에 해당 요소를 저장
            // printf("%d ",rst);
            break;//종료
        }
    }
    // printf("\n");
    return rst;//결과값 반환
}
void rebooking(int *ar){
    int *i,*j;//포인터 2개 선언
    for(i = ar;i<ar+21;i++){//배열 끝까지 반복....ㄱ
        if(*i!=0){
            for(j=ar;j<i;j++)if(*i == *j) *i = (int)changesseat(ar);//중복이 발생하면 changesseat함수 실행
            // printf("i =")
            //배열의 시작점부터 i번째 까지 반복하여
            //=>중복이 없는 수 중에 가장 적은 수를 저장함.
        }
    }

}
int main(){//메인함수
    int  N,arr[22]={0},*parr = arr;//승객의수 N과 크기 21의 배열, 그 배열에 포인터를 연결
    scanf("%d",&N);//승객의 수를 입력받음
    for(int i=0;i<N;i++)scanf("%d",(parr+i));//승객의 예약번호를 저장
    
    if(passengerN(N)==0){//승객의 수가 충분한경우 계속 실행
        rebooking(parr);//rebooking함수 실행
        printf("%d\n",passengerN(N));//승객의 수 충분한지의ㅣ 여부 값 출력
        for(int i=0;i<N;i++)printf("%d ",*(parr+i));//결과값 출력
        printf("\n");
    }
    else printf("%d\n",passengerN(N));//passengerN함수 실행
}
