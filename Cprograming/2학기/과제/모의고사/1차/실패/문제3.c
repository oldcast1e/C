#include  <stdio.h>
#include  <string.h>
void StringAdd(int *chararr,char ch, int index){

}

int Convertor(char x){//숫자 문자를 숫자로 변환한다.
    int rst;
    rst = x - 48;
    return rst;
}

void tmpreset(char *tmp){
    for(int i=0;i<99;i++){
        tmp[i] = ' ';
    }
}

int main(){
    char chararr[1000],*pch = chararr,tmp[100];
    char rst[100]={0},*prst = rst;
    int len=0,a,b;
    int tmpcnt = 0,rstcnt=0;
    
    gets(chararr);
    len = strlen(chararr);
    for(int i=0;i<len-1;i++){

        a = Convertor(*(pch+i));
        b = Convertor(*(pch+i+1));
        // printf("<a = %d| b = %d>",a,b);
        if(a%2==0 && b%2==0){
            rst[rstcnt] = *(pch+i);
            rstcnt++;
            rst[rstcnt] = '*';
            rstcnt ++;
        }

        if(a%2!=0 && b%2!=0){
            // printf("hello");
            rst[rstcnt] = *(pch+i);
            rstcnt++;
            rst[rstcnt] = '+';
            rstcnt ++;
        }
        else{
            rst[rstcnt] = *(pch+i);
            rstcnt++;
        }
        
    }
}
//132456

//최대 8자리 양의 정수를 문자열로 입력받고

//홀수가 연속되는 경우 두 홀수 사이에 +를
//짝수가 연속되는 걍우 두 짝수 사이에 *를 추가한 문자열을 출력하라

/*
1) 문자열길이 구하기 함수 2번 사용
2)void StringAdd(int *chararr,char ch, int index){
◦인자: 
1chararr[] 
2‘+’혹은‘*'가저장된,char형변수ch,
3 int형 변수 index

◦ 해당 배열의 해당 인덱스가 나타내는 위치에 ‘+’ 혹은 ‘*' 를 삽입한다. ◦ 반환 값: 없음


3) int Convertor(char x){
◦ 인자: char형 변수 x
◦ 숫자 문자를 숫자로 변환한다.
◦ 반환값: 숫자 문자에 해당하는 정수

4) main( ) 함수를 다음과 같이 작성하시오.
◦ 문자열을 사용자로부터 입력 받아 char형 배열 str[ ]에 저장한다. 

홀수가 연속되는 경우에 StringAdd() 함수를 호출하여, 
두 홀수 사이에 ‘+’를 추가한다. 2 짝수가 연속되는 경우에도 1과 비슷한 방법으로 처리한다.

◦ 위의 작업을 반복한다.
◦ 문자열을 화면으로 출력한다. 이때 %c 사용금지


*/