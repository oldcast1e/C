#include  <stdio.h>
int arrsum(int *s,int *e){//시작과 끝의 포인터 인자
    int sum = 0,*i;
    for(i=s;i<=e;i++) sum += *i;
    return sum;
}
int main(){
    int N,S,E,arr[100]={0};
    int *parr = arr;
    scanf("%d %d %d",&N,&S,&E);
    for(int i=0;i<N;i++)scanf("%d",(parr+i));
    printf("%d",arrsum((parr+S),(parr+E)));
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//N개의 정수를 입력받아 배열에 저장한 후,
// 배열에 저장된 N개 중에서 첨자 S에서 시작해서 첨자 E까지의 요소의 합을 출력
