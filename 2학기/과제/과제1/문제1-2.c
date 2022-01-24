#include  <stdio.h>

int MAX(int *strdir){//MAX함수 선언
    int maxrst,cnt=0;//반환값과 매개변수 cnt 선언
    while(1){//무한 반복
        if(*(strdir+cnt)==0) break;//해당 요소가 0이면 종료
        if(cnt==0) maxrst = *strdir;//첫번째 반복일때 반환값을 처음 요소값으로 초기화

        if(*(strdir+cnt)>maxrst) maxrst = *(strdir+cnt);//각 반복마다 요소를 비교해 해당 요소가 maxrst보다 크면
        //maxrst로 업데이트
        cnt ++;
        // printf("error 1\n");
    }   
    return maxrst;//결과 반환
}
int MIN(int *strdir){//MIN함수 선언
    int minrst,cnt=0;//반환값과 매개변수 cnt 선언
    while(1){//무한 반복
        if(*(strdir+cnt)==0) break;//해당 요소가 0이면 종료
        if(cnt==0) minrst = *strdir;//첫번째 반복일때 반환값을 처음 요소값으로 초기화
        if(*(strdir+cnt)<minrst) minrst = *(strdir+cnt);//각 반복마다 요소를 비교해 해당 요소가 minrst보다 작으면
        //minrst로 업데이트
        cnt ++;
        // printf("error 2\n");
    }   
    return minrst;//결과 반환
}
int main(){//메인 함수
    int linenum,cnt,max,min,key = 0,opnum;//줄수를 입력받을 linenum 변수와
    //매개변수 cnt, 최대값,최솟값, 조건을 다룰 key 변수,출력 여부를 저장할opnum 변수 선언
    int arr[100],*parr = arr;//크기 100의 배열과 이를 포인터로 연결
    scanf("%d",&linenum);//줄 수를 입력받음
    for(int i=0;i<linenum;i++){//줄 수 만큼 반복하여
        cnt = 0;
        key = 0;
        opnum = 0;//3개의 변수를 초기화

        while(1){//무한 반복하여
            scanf("%d",(parr+cnt));//해당 요소를 입력받음
            if(*(parr+cnt)==0) break;//입력받은 값이 0이면 입력 중지
            cnt ++;//매개 변수 cnt증가
        }
        max = MAX(parr);//최대값 업데이트
        min = MIN(parr);//최솟값 업데이트
        // printf("%d %d\n",max,min);
        for(int k =0;k<cnt;k++){//입력받은 횟수만큼 반복
            if(key == 1 && *(parr+k)!=max && *(parr+k) != min ){//조건값이 1이고 해당수가 최대 또는 최소가 아닐때
            //== 최대와 최소 중간일때
                printf("%d ",*(parr+k));//해당 요소를 출력하고
                opnum++;//출력여부 값을 증가 = 0일때 none을 출력함 = 0이 아니면 none 이 아님
            }
            if(*(parr+k)== max || *(parr+k)== min) key= (key==0?1:0);//해당 요소가 최대또는 최소일때 조건 값을 0으로 업데이트
            //== 조건을 만족할때 (최대와 최소의 사이값일때)출력하기 위함
            // printf("output line\n");
        }
        if(opnum == 0) printf("none");//출력조건이 0인경우 = 출력할게 없을 경우 = 출력이 일어나지 않은 경우 none을 출력
        for(int j=0;j<100;j++) *(parr+j)=0;//배열을 0으로 초기화 = 다음 입력을 위함
        printf("\n");//줄 띄움
        // printf("correct line\n");
    }

}
//입력될 줄 수에 해당하는 정수 N을 입력받음
// 각 줄에서 0이 입력될 때까지만 정수를 입력받음. 각 줄에서 0이후에는 숫자가 없다.
// 각 줄에서 0은 두 번째부터 입력될 수 있음

//각 줄에서 0을 제외한 최대값과 최소값 사이에 위치한 정수를 사용자가 입력받은 순서대로 출력하라.

/*
2
13 7 6 6 2 0
7 3 4 5 6 7 10 
4 0

*/