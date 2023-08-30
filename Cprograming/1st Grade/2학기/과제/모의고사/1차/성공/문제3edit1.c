#include  <stdio.h>
#include  <string.h>
void StringAdd(char *chararr,char ch, int index){//StringAdd함수 정의
    int len = strlen(chararr);//문자열의 길이 구하기
    int tmpcnt = 0;//저장 배열 매개 변수
    char tmp[100];////인자로 받은 인덱스 부터 배열을 저장할 배열정의//인자로 받은 인덱스 부터 배열을 저장할 배열정의
    for(int i=index;i<len;i++){//배열 저장
        tmp[tmpcnt] = chararr[i];
        tmpcnt++;
    }
    tmp[tmpcnt] = '\0';//저장 배열의 마지막 구분
    // printf("tmp: %s\n",tmp);

    for(int i=index;i<len;i++) chararr[i] = '\0';//해당 인덱스부터 널값 저장 = 나중에 배열 접합위함
    chararr[index] = ch;//해당 인덱스의 요소에 인자로 받은 값 저장
    strcat(chararr,tmp);//문자열 접합
    len = strlen(chararr);//문자열 길이 구하기 = 문자열 길이가 바뀌었으므로 다시 구함
    chararr[len] = '\0';//배열의 끝을 널값 = 배열 종료 지점

    // printf("chararr: %s",chararr);


}

int Convertor(char x){//숫자 문자를 숫자로 변환한다.
    int rst;
    rst = x - 48;//숫자로 변환 후
    return rst;//반환
}

void tmpreset(char *tmp){//tmp를 리셋하는 함수
    for(int i=0;i<99;i++){
        tmp[i] = ' ';
    }
}

int main(){//메인함수
    char chararr[1000],*pch = chararr,tmp[100];//크기 1000의 문자열 두개 선언

    char ch;//인자로 쓸 char형 변수
    int len=0,a,b,index;//문자열 길이 및 인덱스 변수
    int tmpcnt = 0,rstcnt=0;//배열 입력시 사용 매개 변수
    
    gets(chararr);//문자열 입력받고
    len = strlen(chararr);//문자열 길이 저자ㅣㅇ
    for(int i=0;i<len-1;i++){//문자열 길이만큼 반복

    //-1을 한 이유는 한번에 두값을 비교하므로

        a = Convertor(*(pch+i));
        b = Convertor(*(pch+i+1));//a,b 정수화
        // printf("<a = %d| b = %d>",a,b);
        if(a%2==0 && b%2==0){//두개 모두 짝수이면

            ch = '*';//추가값
            index = i+1;//인덱스 증가: 다음요소를 바꾸므로
            StringAdd(chararr,ch,index);
            // len = strlen(chararr);
            i++;
            len++;
        }

        else if(a%2!=0 && b%2!=0){
            // printf("hello");
            ch = '+';//추가값
            index = i+1;//인덱스 증가: 다음요소를 바꾸므로
            StringAdd(chararr,ch,index);
            // len = strlen(chararr);
            i ++;
            len++;
            
        }
        
    }
    printf("%s",chararr);//결과출력
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