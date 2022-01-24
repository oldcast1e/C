#include  <stdio.h>

int num_digit(int x){//num_digit함수 정의
    int cnt=0;//자리수 변수 초기화
    while (x>0)//x가 0이상일동안
    {
        x/=10;//10으로 나누고
        cnt++;//자리수를 1올림
    }
    return cnt;//자리수 반환
}
int convert_top(int N,int num){//정수 / 자리수 - 홀수 인경우
//convert_top함수 정의

    int cnt = 1;//앞의 두자리를 출력하기 위해,
    // (숫자 - 숫자%10^(숫자의 자리수 -2))/숫자%10^(숫자의 자리수 -2)
    if(num==1){//마지막 숫자일때
        printf("*");//*출력후
        return 0;//0을 반환
    }
    else{
        num -= 2;//마지막 숫자가 아닌 경우 자리수를 -2
        for(int i=0;i<num;i++){//자리수 만큼 반복하여
            cnt *= 10;// 앞 두자리를 뽑아 내기 위해 10의 num제곱을 만듦
        }
        // if('a'<=((N-N%cnt)/N%cnt)&&((N-N%cnt)/N%cnt)<='z')
        printf("%c",( 'a'<=((N-N%cnt)/cnt)&&((N-N%cnt)/cnt)<='z'|| 'A'<=((N-N%cnt)/cnt)&&((N-N%cnt)/cnt)<='Z'?(N-N%cnt)/cnt:'*'));
        //해당 값이 영어 소문자/대문자인 경우 출력하고 아닌 경우 *출력
        return N%cnt;//앞 두자리를 뺀 숫자를 리턴함.
    }

    
}
int convert_bottom(int N){//convert_bottom함수 정의 - 짝수

    printf("%c",'a'<=(N%100)&&(N%100)<='z' || 'A'<=(N%100)&&(N%100)<='Z'?N%100:'*');//해당 조건을 만족하면 출력
    return 0;//0반환
}
int main(){
    
    int N;//입력받을 정수 선언
    scanf("%d",&N);//정수를 입력받고
    int num = num_digit(N);//자리수 계산 함수 실행
    int rst = (num%2==0?1:0);//자리수가 짝수이면 1 홀수이면 0
    while(rst==1){//짝수이면

        if(N==0) break;//계산할 수가 0이면 종료
        convert_bottom(N);//함수 반복 실행
        N/=100;//뒤부터 출력하므로 뒤 두자리 삭제

    }
    while(rst==0){//홀수이면
        
        if(N==0&&num==0) break;//해당 조건 만족 시 종료: 종료 조건
        N = convert_top(N,num);//함수 실행한 값을 N에 저장 N = N%cnt
        if(num==1) num=0;//반복횟수가 1일때 이를 0으로 바꿈
        else num -=2;//아닌 경우 반복횟수 -=2;

    }
    
}
