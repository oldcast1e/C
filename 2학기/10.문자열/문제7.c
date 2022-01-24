#include  <stdio.h>
void numdistinc(char *parr){//자릿수를 출력하는 함수
    int rstnum = *parr-48;//문자값을 정수로 변환
    //아스키코드 이용
    // printf("%d\n",rstnum);

    if(rstnum==1) printf("one");//1이면 one
    else if(rstnum==2) printf("two");//2이면 two
    else if(rstnum==3) printf("three");//3이면three
    else if(rstnum==4) printf("four");//4이면four
    else if(rstnum==5) printf("five");//
    else if(rstnum==6) printf("six");//,,,,자릿수 출력
    else if(rstnum==7) printf("seven");//
    else if(rstnum==8) printf("eight");//,,,,자릿수 출력
    else if(rstnum==9) printf("nine");//

}
int main(){//메인함수

    char num[1000],*pnum=num,cnt=0;///크기1000의 배열 선언 및 포인터 연결
    scanf("%s",num);//문자열을 입력받음
    int dit =0;//자릿수 변수 선언
    for(int i=0;i<101;i++){//20번 반복
        if(*(pnum+i)== '\0') break;//널 문자가 입력되면 = 문자열 입력이 종료되면
        dit ++;//문자 개수 변수 증가
    }
    for(int i=0;i<dit;i++){//문자 자릿수 반큼 반복
        if(dit==4){//자릿수의 계수가 4이면
            numdistinc((pnum+i));//함수 실행
            if(*(pnum+i)!=48){//0이 아닌경우
                if(i==0 )printf(" THO ");//천
                else if(i==1)printf(" HUN ");//백
                else if(i==2) printf(" TEN ");//십
            }
        }
        else if(dit==3){//3이면
            numdistinc((pnum+i));//함수 실행
            if(*(pnum+i)!=48){//0이 아닌경우
                if(i==0)printf(" HUN ");//백
                else if(i==1) printf(" TEN ");//십
            }
        }
        else if(dit==2){//2이면
            numdistinc((pnum+i));//함수 실행
            if(*(pnum+i)!=48) if(i==0) printf(" TEN ");//십
        }
        else if(dit==1)numdistinc((pnum+i));//1이면
    }
}
//사용자로부터 정수 n을 입력받아 그 값을 표현하는 문자욜을 출력하는 프로그램을 작성하라
//단 1000보다 작은 정수
//천 THO
//백 HUN
//십 TEN
//일 해당숫자