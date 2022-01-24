//5-1
#include<stdio.h>

int main(){

    int N;
    scanf("%d",&N);
    if(N<0)//N이 0보다 작으면
        printf("cold, indoor");//를 출력
    else if(0<=N && N<40)//N이 0도 이상,40도 미만이면 
        printf("moderate, outdoor");//를 출력
    else//위의 조건을 만족하지 않는경우=(40도 이상)
        printf("hot, indoor");//를 출력

}