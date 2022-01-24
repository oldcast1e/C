#include  <stdio.h>
#include <string.h>
int main(){ //메인함수
    int n,cnt=0;//입력받을 정수값과 문자수=요소넘버
    char arr[9];//크기ㅣ 9의 배열 선언
    scanf("%d",&n);//임의의 정수를 입력받음
    while(n>0){//N이 0이 될때까지
        arr[cnt] = (char)(n%10+48);//해당 정수를 나머지 연산 시키고 아스키코드 변환
        n/=10;//다음 숫자를 위해 10으로 나눔
        if(n<=0) break;//0보다 작으면 종료
        cnt++;//문자수 증가
    }
    printf("%s",arr);//결과 출력
    //정수를 한 자리씩 문자로 변환 후 
    //마지막 자리수부터 차례로 문자배열에 저장




}