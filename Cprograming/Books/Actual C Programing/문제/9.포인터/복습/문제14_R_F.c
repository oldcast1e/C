#include  <stdio.h>
void ABC(int *strdir,int len){
    int max,tmp,*rstdir = NULL;
    // printf("first value : %d\n",*strdir);
    for(int *pot = strdir;pot<(strdir+len);pot++){
        if(pot == strdir) max = *pot;
        else if(*pot > max){
                // printf("previous max: %d | new max: %d\n",max,*pot);
                max = *pot;

                tmp = *strdir;
                *strdir = max;
                *pot = tmp;
        }      
    }
}
int main(){
    int arr[10];
    int *parr = arr;
    for(int i=0;i<10;i++) scanf("%d",(parr+i));

    for(int j=0;j<9;j++){
        ABC((parr+j),(10-j));
        // printf("     repeat num:%d      \n",j);
    } 
    for(int i=0;i<10;i++) printf("%d ",*(parr+i));
}




//1 3 5 7 9 2 4 6 8 10
//13 56 27 89 43 76 32 68 91 8
//10개의 정수를 입력으로 받아, 가장 큰 수부터 내림차 수으로 정렬하여 출력하는프로그램

//main함수
//배열에서 조사 시작위치의 주소와 길이를 인수로 하여, ABC함수를 9번 반복(매 호출 시 길이는 9,8,7,6,,)

//ABC함수: 인자-(조사 시작 원소의 주소/ 조사할 원소의 개수)
//       - 배열에서 조사 대상의 첫번째 수부터 마지막 정수까지 중 가장 큰 수를 찾고 맨처음 수와 교환