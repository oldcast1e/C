#include <stdio.h>
int passengerN(){

}
int rebooking(){

}
int changeseat(int *pnum){

}
int main(){
    int N,arr[100],*pnum = arr,cnt,repval;
    int ovr[21] = {0}, *povr = ovr;

    scanf("%d",&N);
    for (int i = 0; i < N; i++) scanf("%d", (pnum + i));
    repval = (passengerN==0?1:-1);
    printf("%d\n",passengerN);
    if(repval == 1){
        for (int i = 0; i < N; i++){ //N번 반복하여....ㄱ
            for (int j = 0; j < N; j++){ //N번 반복하여(2).....ㄴ
                if (*(pnum + i) == *(pnum + j)){//ㄱ과 ㄴ의 요소가 같으면
                    *(povr + i) += 1; //중복을 저장하는 변수의 요소값을 1증가
                }
            }
        }
        for (int i = 0; i < N; i++){
            if(*(povr+i)>2);
        }
        



    }

    
}
//21인승 버스의 좌석 중복 여부를 확읺는 프로그램을 작정
//버스 좌석 번호는 1~21까지 차례로 부여

//승객의 수는 21을 넘지 않으며 최소 5명이상 예약을 해야 버스가 운행
//승객은 좌석 예약을 위해 한명 씩 1~21사이의 임의의 숫자를 입력해 좌석을 예약
//이때 좌석을 예약에 중복이 있는 경우 중복 예약된 좌석 번호와 예약 중복 횟수를 알려주는 프로그램을 작성하라

//승객인 수 N(5~21)을 입력하고 그 다음 줄에 N번 반복하여 1~21사이의 숫자 입력
//입력하는 숫자의 순서 = 손님들의 예약하는 순서, 중복 예약이 없는 경우 0 출력

//승객의 수가 5보다 작은 경우 -1출력
