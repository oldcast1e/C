#include  <stdio.h>
int main() 
{
    int n,m,k=1;//3개의 정수형 변수 선언
    scanf("%d",&n);//정수를 입력받음
    m = n-1;//m에 n-1을 대입(항상 첫번째 별은 n-1번 빈칸)
    while(k<=n){//n이 k보다 크거나 같을 때 반복
        for(int i=0;i<m;i++){
            printf(" ");//빈칸 출력
        }
        for(int i=1;i<=(2*k-1);i++){
            printf("*");//별 출력(2n-1개 씩 출력)
        }
        printf("\n");//열 마다 띄움
        m -=1;//삼각형 모양이므로 빈칸은 1씩 줄음
        k +=1;//반복을 위해 k+1
    }


}
