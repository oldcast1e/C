#include  <stdio.h>
int main(){
    int cnt = 0,rstcnt = 0,max=-1,key = 0;//반복을 제어할 변수(문자열입력) cnt와 결과값을 저장하기 위해 필요한 매개변수 rstcnt선언
    char arr[100],*parr = arr;//크기 100의 배열 선언 및 포인터 연결
    char rst[100],*prst = rst;//결과를 저장할 배열 선언 및 포인터 연결
    while(1){
        scanf("%c",(parr+cnt));//cnt는 문자를 입력받기 위해 필요한 필수 정수형 변수
        *(rst+rstcnt) = *(parr+cnt);//결과값 배열에 해당 문자 저장
        if(*(parr+cnt)<97 || *(parr+cnt)>122){//입력받은 배열의 요소의 값이 소문자가 아닌경우 = 소문자 입력이 끝난 경우
            if(rstcnt>max &&  97<=*(parr+cnt-1) && *(parr+cnt-1)<=122) max  = rstcnt;//가장 긴 단어의 길이 저장

            for(int j=0;j<rstcnt;j++)printf("%c",*(rst+j));//저장된 단어를 출력하고
            if(97<= *(parr+cnt-1) && *(parr+cnt-1) <= 122)printf("\n");//그 전의 문자가 소문자이면 칸 띄움

            for(int k=0;k<100;k++) *(prst+k) = 0;//(결과)단어 배열 초기화
            rstcnt = 0;//단어 저장 순서 변수를 0으로 초기화
        } 
        else rstcnt++;//소문작 아닌 경우 rstcnt증가 = 결과값 저장하기 위함
        if(*(parr+cnt)=='#') break;//입력받은 값이 #인 경우 종료
        cnt ++;//cnt증가
    }
    printf("%d",max);//가장 긴 단어의 길이 출력

}
//#문자가 입력될 때까지 문자를 입력받음
//소문자로 구성된 단어들을 출력하라

//각 단어들은 소문자가 아닌 문자로 구분되고, 마지막으로 길이가  가장 긴 단어의 길이을 출력하라.