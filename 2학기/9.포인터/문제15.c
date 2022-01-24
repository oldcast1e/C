#include  <stdio.h>
void ABC(int *strdir,int len){//ABC함수 선언/인자는 시작점과 길이
    int max,tmp,*rstdir = NULL;//가장 큰 값을 저장할 변수 max와 변환시 사용할 tmp
    //위치 저장할 rstdir포인터 선언
    // printf("first value : %d\n",*strdir);
    for(int *pot = strdir;pot<(strdir+len);pot++){//시작점부터 끝까지 = 주어진 시작점 + 길이
        if(pot == strdir) max = *pot;//첫번째 반복시 Max값을 초기화
        else if(*pot > max){//해당 요소가 max보다 큰 경우
                // printf("previous max: %d | new max: %d\n",max,*pot);
                max = *pot;//max값을 해당 요소값으로 업데이트

                tmp = *strdir;//시작한 위치의 요소의 값을 tmp변수에 저장
                *strdir = max;//최대값을 덮어씌우고
                *pot = tmp;//해당위치의 값에 tmp를 저장

                //=>조사대상의 첫번째 정수와 가장 큰 정수(해당 조사 정수)를 바꿈
        }      
    }
}
int main(){//메인함수
    int arr[10];//크기 10의 배열 선언
    int *parr = arr;//배열과 포인터를 연결
    for(int i=0;i<10;i++) scanf("%d",(parr+i));//10번 반복하여 정수를 입력받음

    for(int j=0;j<9;j++){//9번 반복하여
        ABC((parr+j),(10-j));//함수 실행
        // printf("     repeat num:%d      \n",j);
    } 
    for(int i=0;i<10;i++) printf("%d ",*(parr+i));//결과출력
}




//1 3 5 7 9 2 4 6 8 10
//13 56 27 89 43 76 32 68 91 8
//10개의 정수를 입력으로 받아, 가장 큰 수부터 내림차 수으로 정렬하여 출력하는프로그램

//main함수
//배열에서 조사 시작위치의 주소와 길이를 인수로 하여, ABC함수를 9번 반복(매 호출 시 길이는 9,8,7,6,,)

//ABC함수: 인자-(조사 시작 원소의 주소/ 조사할 원소의 개수)
//       - 배열에서 조사 대상의 첫번째 수부터 마지막 정수까지 중 가장 큰 수를 찾고 맨처음 수와 교환