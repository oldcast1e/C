#include  <stdio.h>
int main(){

    int n,m=1;//입력받을 정수와 와일문에 사용할 정수 선언
    scanf("%d",&n);//정수 입력받음
    int cnt = n-1, k = cnt;//한칸을 띄울 변수 만듦
    while(m<=n){//m이n보다 작거나 같을때 반복
        if(m!=1)//m이 1이 아닌경우만 줄 바꿈=마지막줄을 띄우면 안됨
            printf("\n");
        for(int i=0;i<cnt;i++){//삼각형을 만들기위해 한칸 띄움
            printf(" ");
        }
        k--;//k를 줄이는 이유는 점점 한칸씩 줄여하기때문
        cnt = k;//k을 cnt에 대입
        for(int j=1;j<=2*m-1;j++){//X,O를 출력하는 코드

            if(m==n){//마지막줄은 X로
                printf("X");
            }
            else{//마지막줄이 아닌 경우
                if(j==1 || j==2*m-1){
                    printf("X");//첫번째와 마지막에 X출력
                }
                else//아닌 경우
                    printf("O");//O출력
            }
        }
        m++;//반복을 위한 값 증가
    }
}