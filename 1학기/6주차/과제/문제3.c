#include  <stdio.h>
int main(){

    int n,i=1;//입력받을 정수와 임의의 정수 선언
    scanf("%d",&n);//입력받음
    int cnt = n-1;//반복할 횟수
    int k = cnt,m=n;//2개의 정수 선언

    int cnt2 = 0;//이줄과 아래의 줄의 변수는 다이아몬드가 줄어들때 사용
    int cnt3;//
    while(i<n){//다이아몬드가 볼록해질때
        while(cnt>0){
            printf(" ");//공간
            cnt --;//반복
        }
        k --;//k를 줄이는 이유는 반복하는 횟수가 커지기때문
        cnt = k;//

        for(int j=1;j<=2*i-1;j++){
            printf("*");//별을 출력
        }
        i++;
        printf("\n");//이때는 위치상관없이 줄 띄움
    }
    
    while(m>0){//별이 가장 많은 부분부터 적어짐
        for(int i=(m*2-1);i>0;i--){//별의 반복
            printf("*");//별 출력
        }
        if(cnt2+1!=n)//가장 아래쪽을 띄우지 않는 조건
            printf("\n");//열 띄움
        m--;
        cnt2 +=1;
        cnt3 = cnt2;//간격을 맞추는 코드
        while(cnt3>0){
            printf(" ");
            cnt3 --;//cnt3을 통해 간격을 맞춤
        }
        
    }
}