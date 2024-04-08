#include  <stdio.h>

void ABC(int *st,int size){
    int max,tmp,*dir;
    for(int i=0;i<size;i++){//반복횟수 9,8,7,6,,,,,1
        if(i==0) max= *(st+9-size);
        else if(*(st+9-size+i)>max){
            max = *(st+9-size+i);
            dir = &max;
        } 
    }
    tmp = *(st+10-size);
    *(st+10-size) = max;
    *dir = tmp;
    // int *i,max,tmp;
    // for(i = st;i<st+size;i++){
    //     if(i==st) max  = *i;
    //     else if(*i >max) max = *i;
    // }
    
}

int main(){
    int arr[10];
    int *pnum = arr,*st = arr;
    for(int i=0;i<10;i++)scanf("%d",(pnum+i));
    for(int i=1;i<10;i++) ABC((st+i),10-i);
    for(int i=0;i<10;i++) printf("%d ",*(arr+i));


}
//10개의 정수를 입력으로 받아, 가장 큰 수부터 내림차순으로 정렬하여 출력하는 프로그램 작성
//메인함수: 배열에서 조사 시작의 위치의 주소와 길이를 인수로 하여 ABC()함수를 9번 반복호출(호출 시 길이는 10,9,8,,,,으로 변환)
