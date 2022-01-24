#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int input(int *p){
    int cnt = 0;
    for(int i=0;;i++){
        scanf("%d",(p+i));
        if(*(p+i)== -1){
            cnt = i;break;
        }
    }
    return cnt;

}
/*
배열 x의 시작 주소를 인자로 받아 종료 조건까지 정수를 입력받아 배열에 저장하고, 배
열 원소의 개수를 반환한다. 
*/

int *sel_next(int *p, int N, int M){

    int *rstdir;
    int sum = 0;

    for(int i=M;i<N;i++){
        sum+= *(p+i);
        if(sum<=10){
            rstdir = (p+i);
            if(*(p+i+1)==-1) break;
        }
    }
    return rstdir;
}
/*
◦ 함수 원형: int *sel_next(int *p, int N, int M)
◦ 배열 x의 시작 주소와 배열의 크기 N, 
원소 값의 합 계산을 시작할 원소의 위치 M을 인자로 받아, 
원소 들의 합이 10을 초과하기 바로 전의 원소의 주소를 반환 한다. 원소들의
합이 10을 초과하지 않은 채
*/

int number(int *p, int *q){

    int sum = 0,*i;
    int rst = 0;
    for(i=p;i<=q;i++){
        sum += *i;
        if(sum<=10){
            rst += *i;
            rst *=10;
            if(*(i+1)==-1) break;
        }
    }
    return rst /=10;
}
/*
◦ x[M]의 위치와 sel_next에서 반환된 위치를 인자로 받아, 
두 포인터 사이의 한 자리 정수
를 모아, 하나의 정수로 만들어 반환 한다. 

*/


int main(){

    int str[101],*pstr = str;
    int cnt = input(str),M;

    scanf("%d",&M);//원소 값의 합 계산을 시작할 원소의 위치 M을

    int *rstdir = sel_next(str,cnt,M);
    int rstnum = number((pstr+M),rstdir);

    printf("%d",rstnum);


}

//1 2 1 3 3 2 5 -1
//1