#include  <stdio.h>
int arrsum(int *s,int *e){//시작과 끝의 포인터 인자
    int sum = 0,*i;//합을 저장할 변수 sum과 포인터 선언
    for(i=s;i<=e;i++) sum += *i;//시작을 나타내는 포인터에서 끝을 나타내는 포인터까지 반복하여
    //sum에 해당 포인터 요소를 더함
    return sum;//sum을 반환
}
int main(){
    int N,S,E,arr[100]={0};//정수형 변수 3개와 크기 100의 배열 선언
    int *parr = arr;//배열과 포인터를 연결
    scanf("%d %d %d",&N,&S,&E);//3개의 정수를 입력받고
    for(int i=0;i<N;i++)scanf("%d",(parr+i));//N번 반복하여 숫자를 입력받음
    printf("%d",arrsum((parr+S),(parr+E)));//구간에 해당되는 배열 요소의 총합의 반환값(결과값)출력
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//N개의 정수를 입력받아 배열에 저장한 후,
// 배열에 저장된 N개 중에서 첨자 S에서 시작해서 첨자 E까지의 요소의 합을 출력
