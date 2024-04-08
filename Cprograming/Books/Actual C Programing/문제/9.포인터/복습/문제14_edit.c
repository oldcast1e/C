#include  <stdio.h>

void ABC(int *st,int size){
    int max,*dir;
    for(int i=10-size;i<10;i++){//0~9,1~9
        if(i==0) max = *st;
        else if(*(st+i)>max){
            max = *(st+i);
            dir = (st+i);
            printf("Checking,,i=%d\n",i);
        } 
    }
    *dir = *st;
    *st = max;
}

int main(){
    int arr[10];
    int *pnum = arr,*st = arr;
    for(int i=0;i<10;i++)scanf("%d",(pnum+i));
    for(int i=10;i>=2;i--) ABC((st+10-i),i);
    // for(int i=10;i>=2;i--) ABC((st+10-i),i);//st(0)/st(1)/st(2),,,,
    //i=10,9,8,7,6,5,4,,,,
    for(int i=0;i<10;i++)printf("%d ",*(pnum+i));
   


}
//10개의 정수를 입력으로 받아, 가장 큰 수부터 내림차순으로 정렬하여 출력하는 프로그램 작성
//메인함수: 배열에서 조사 시작의 위치의 주소와 길이를 인수로 하여 ABC()함수를 9번 반복호출(호출 시 길이는 10,9,8,,,,으로 변환)
