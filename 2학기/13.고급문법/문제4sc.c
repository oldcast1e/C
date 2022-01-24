#include<stdio.h>
#include<string.h>
#include  <stdlib.h>
#include  <math.h>
void change(char *arr,int n,char *rst){//16진수를 문자열로 변환
//인자를 문자열과 입력받은 정수, 16진수 결과 배열 함

    int cnt=1;//반복 매개변수
    if(n<=15){//15보다 작거나 같은 경우
        arr[0] = '0';//무조건 첫번째 값은 0임
        if(n>9)arr[1] = 55 + n; //9보다 크면 알파벳임
        else arr[1] = n + 48;//정수화
    }
    else{//아닌 겨우
        while (n>0){//16진수로 만들기
            arr[cnt] = n%16 + 48;
            n/=16;
            cnt --;
        }
    }    
}
int main(){
    char ar1[3]={'\0'},ar2[3]={'\0'},ar3[3]={'\0'},ar4[3]={'\0'};
    char *par1 = ar1,*par2 = ar2,*par3 = ar3,*par4 = ar4;//배열 및 포인터 선언

    char rst[9]={0}; for(int i=0;i<8;i++) rst[i] = '\0';//변환 결과 저장 배열

    int a,b,c,d;//입력받을 정수 4개
    scanf("%d %d %d %d",&a,&b,&c,&d);//입력
    change(par1,a,rst);change(par2,b,rst);change(par3,c,rst);change(par4,d,rst);//함수 실행
    // 16 84 30 09
    strncat(rst,ar1,2);strcat(rst,ar2);strcat(rst,ar3);strcat(rst,ar4);//문자열 접합
    int result = 0;//10진수 변환 후 최종 결과값
    int cnt = 0;

    for (int i = strlen(rst) - 1; i >= 0; i--){//역순 반복
        char ch = rst[i];// 각 자릿수에 해당 문자
        if (ch >= 48 && ch <= 57)result += (ch - 48) * pow(16, cnt);  // 문자가 0~9
            // 문자에서 0에 해당하는 ASCII 코드 값을 빼고 16에 자릿수를 거듭제곱한 값을 곱함
        else if (ch >= 65 && ch <= 70) result += (ch - (65 - 10)) * pow(16, cnt);// 대문자
            // 문자에서 A에 해당하는 값을 빼고 16에 자릿수를 거듭제곱한 값을 곱함
        cnt++;
    }
    printf("%d", result);   
}