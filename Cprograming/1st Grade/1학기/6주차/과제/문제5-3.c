#include  <stdio.h>
int main(){
    
    int n,rst=0;//입력받을 정수와 결과값 선언
    scanf("%d",&n);//입력받음
    int evenrst=0,oddrst=0,cnt;//짝수,홀수 역수화 숫자받을 변수 정의,cnt는 도와주는 변수
    int en=0,on=0;//역수를 만들때 첫번째 더할때는 곱하지 않게 설정

    while(n>0){
        cnt = n%10;//n을 나머지 연산
        if(cnt%2==0){//나머지 연산 값이 짝수인경우
            if(en==0)//en이 0이면 결과값에 그냥 더함
                evenrst +=cnt;
            else{//아닌경우
                evenrst*=10;//원래있는 값을 10곱해준 후
                evenrst +=cnt;//나머지 값을 더해줌
            }
            en++;//en을 1올림
        }
        else {//2로 나눠지지 않는 경우(홀수)
            if(on==0)//on값을 판단해
                oddrst +=cnt;//첫번째 계산인 경우 그냥 결과값에 더함
            else{//아닌 경우

                oddrst*=10;//원래의 값에 10을 곱하고
                oddrst +=cnt;//나머지 연산 값을 더함
            }
            on++;
                
        }
        n /=10;//n을 10으로 나눔=반복 위함
        
        
    }
    printf("%d %d",evenrst,oddrst);//결과값 출력
   
    
}