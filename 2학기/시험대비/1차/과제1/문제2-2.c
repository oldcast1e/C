#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int passengerN(int n){
    int rst;
    if(n<5) return -1;
    else return 0;
}
/*
◦ n: 승객 수
◦ 반환 값: 승객 수가 부족하면 –1, 승객 수가 충분하면 0을 반환한다.
*/

int changeseat(int *ar){

    int rst = 1;
    int *i,*j;
    for(i= ar; ;i++){
        if(*i==0) break;
        
        for(j= ar; ;j++){
            if(*j==0) break;
            if(rst == *j) rst ++;
        }   
    }
    return rst;
}
/*
◦ ar: 처음 예약된 버스 좌석 번호가 저장되어 있는 배열의 이름
◦ 1~21 사이의 숫자들 중 배열에 존재하지 않으면서 가장 작은 숫자를 찾아준다. 
◦ 반환 값 : 찾아낸 가장 작은 숫자를 반환한다
*/

void rebooking(int *ar){

    int *i,*j;
    for(i= ar; ;i++){
        if(*i==0) break;
        
        for(j = ar; j<i; j++){
            if(*i == *j){
                *i  = changeseat(ar);
            }
        }

    }
}
/*
◦ ar: 처음 예약된 버스 좌석 번호가 저장되어 있는 배열의 이름
◦ 중복된 좌석 번호가 존재하는지 확인하고, 중복된 좌석이 존재하는 경우, 
changeseat 함수를 호출하여 중복된 좌석 번호를 빠른 번호의 빈 좌석 번호로 대체한다.
단, 중복된 좌석들 중 나중에 예약한 좌석 번호를 빈 좌석으로 대체한다.
*/



int main(){

    int passanger,cnt = 0,key,notrp=0;
    int ar[22],*pst = ar;
    for(int i=0;i<22;i++)*(pst+i) = 0;
    scanf("%d",&passanger);
    
    while(1){
        scanf("%d",(pst+cnt));
        cnt++;
        if(cnt == passanger) break;
    }
    //순서대로 재정렬
    // for(int i=0;i<cnt;i++){
    //     int tmp;
    //     for(int j=i;j<cnt;j++){
    //         if(*(pst+i) > *(pst+j)){
    //             tmp = *(pst+i);
    //             *(pst+i) = *(pst+j);
    //             *(pst+j) = tmp;
    //         }
    //     }   
    // }
    rebooking(ar);
    printf("%d\n",passengerN(passanger));
    if(passengerN(passanger)==0){
        for(int j=0;j<cnt;j++){
            printf("%d ",*(pst+j));
        }
    }
}
//7
//1 2 3 3 4 5 6
//8 8 6 8 6 1