#include  <stdio.h>

int add_to_k(int *st,int *ed){//add_to_k함수선언
    //시작과 끝을 나타내는 포인터를 인자로 함
    int *i,sum=0;//포인터 변수i와 합을 저장할 변수 sum 선언
    for(i=st;i<ed;i++) sum += *i;//해당 포인터 구간에서 sum에 각 포인터 요소값을 더함
    return sum;//sum값을 반환함

}

int main(){
    int n,d[100],*st = d,*ed = (d+1),sum=0;
    //입력받을 정수를 저장할 정수형 변수와 결과값, 크기 100의 배열 선언
    //시작점을 나타내는 포인터와 끝점을 나타내는 포인터 선언

    //끝점은 첫번째ㅐ 반복시 두번째로 잡음
    int *pnum = d;//입력을 받기위해 배열과 포인터 연결
    scanf("%d",&n);//정수를 입력받음
    for(int i=0;i<n;i++){//입력받은 정수만큼 반복하여
        scanf("%d",(pnum+i));//정수를 입력받음
    }
    for(int i=0;i<n;i++){//n번 반복하여
        sum += add_to_k(st,ed);//함수실행
        ed ++;//끝점의 위치를 늘림 = d + (d+(d+1))....위함
        // printf("rst = %d\n",sum);
    } 
    printf("%d",sum);//결과값 출력

}

//N개의 정수를 입력받아 (N<=100) int 형 배열 d[100]에 저장하고, 다음 수식의 값을 출력하는 프로그램을 작성하라

