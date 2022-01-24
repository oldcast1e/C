#include  <stdio.h>
#include<string.h>

int check(char *strdir){//회문 여부를 판단하는 함수/ 배열의 시작점을 인자로 받음
    int rst=0,len=0,cnt=0,icnt;//결과값을 0으로 초기화, 배열의 길이, 반복횟수 카운트
    char frt[20],bck[20];//크기 15의 배열 두개 선언 = 반으로 나눠서 비교할 예정
    while(1){
        if(*(strdir+len)=='\0') break;
        len++;//배열의 길이 구하기
    }
    for(int i=0;i<len/2;i++) frt[i]= *(strdir+i);//2=>0~1
    //배열을 두개로 나눌때 첫번째 배열
    //홀수면 중간값 전까지, 짝수면 절반 (홀수인경우 중간값을 생각안해도됨 = 대칭이면 상관없으므로)
    icnt=(len%2==0?len/2-1:len/2);//두번째 비교 시, 반복횟수
    for(int i=len-1;i>icnt;i--){//배열의 끝부터 중간까지 역순으로
        bck[cnt]= *(strdir+i); //4~3 두번째 배열에 저장
        cnt++;
    } 
    // printf("%s\n",frt);
    // printf("%s\n",bck);
    rst = (strncmp(frt,bck,icnt)==0?1:0);//배열을 비교, 결과가 0이면 똑같은 문자열임.
    
    return rst;
}
int main(){//메인 함수
    char str[31],*pstr = str;//크기 30의 배열과 포인터 연결
    scanf("%s",str);//배열을 입력받고
    printf("%d %d",(int)strlen(str),check(pstr));//배열의 길이를 구하는 함수의 반환값(결과) , 회문여부 출력
}
//공백을 제외한 문자열을 입력받아
//입력받은 문자열의 회문 여부를 판단하는 프로그램
//출력: 문자열의 크기. 회문 여부(맞으면 1아니면 0)

//입력받은 문자열의 길이(n)가 홀수인경우 ex)heleh 5/2=2 ->앞에서부터 n/2개 뒤에서부터 n/2개
//입력받은 문자열의 길이(n)가 짝수인경우 ex)worrow

//aibohobia