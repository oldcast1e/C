#include  <stdio.h>

int MAX(int *strdir){//MAX함수 선언: 인자를 배열 시작주소 가짐
    int maxrst,cnt=0;//반환할 결과값과 0이 나올때까지 배열의 저장 주소를 업데이트할 cnt정수 선언
    while(1){//무한 반복
        if(*(strdir+cnt)==0) break;//해당 배열 요소가 0인 경우 종료
        if(cnt==0) maxrst = *strdir;//첫번째 반복시, 결과값에 시작점의 요소값을 저장

        if(*(strdir+cnt)>maxrst) maxrst = *(strdir+cnt);//해당 요소가 최댓값보다 큰 경우 최댓값을 업데이트
        cnt ++;//cnt 증가
        // printf("error 1\n");
    }   
    return maxrst;//결과값 반환
}

int MIN(int *strdir){//MIN함수 선언: 인자를 배열 시작주소 가짐
    int minrst,cnt=0;//반환할 결과값과 0이 나올때까지 배열의 저장 주소를 업데이트할 cnt정수 선언
    while(1){//무한 반복

        if(*(strdir+cnt)==0) break;//해당 배열 요소가 0인 경우 종료
        if(cnt==0) minrst = *strdir;//첫번째 반복시, 결과값에 시작점의 요소값을 저장

        if(*(strdir+cnt)<minrst) minrst = *(strdir+cnt);//해당 요소가 최솟값보다 작은 경우 최댓값을 업데이트
        cnt ++;//cnt값 증가
        // printf("error 2\n");
    }   
    return minrst;//최솟값 반환

}
int main(){//main함수 선언

    int linenum,cnt;//입력받을 줄 수을 저장할 linenum변수와 각 줄 마다 배열에 입력받기위해 필요한 매개변수 cnt선언
    int arr[100],*parr = arr;//크기100의 배열과 포인터 연결
    scanf("%d",&linenum);//줄 수를 입력받음
    for(int i=0;i<linenum;i++){//줄 수 만큼 반복
        cnt = 0;//초기화
        while(1){//0이 나올 때까지 반복
            scanf("%d",(parr+cnt));//해당 배열에 저장
            if(*(parr+cnt)==0) break;//0이 나오면 종료
            cnt ++;//cnt증가
        }
        printf("%d %d\n",MAX(parr),MIN(parr));//해당 줄의 최댓값과 최솟값을 출력
        for(int j=0;j<100;j++) *(parr+j)=0;//다음 입력을 위해 배열을 0으로 초기화
    }

}
//입력될 줄 수에 해당하는 정수 N을 입력받음
// 각 줄에서 0이 입력될 때까지만 정수를 입력받음. 각 줄에서 0이후에는 숫자가 없다.
// 각 줄에서 0은 두 번째부터 입력될 수 있음

//각 줄에서 0을 제외한 최대값과 최소값 사이에 위치한 정수를 사용자가 입력받은 순서대로 출력하라.