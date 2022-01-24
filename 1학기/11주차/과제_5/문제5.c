#include <stdio.h>

int add_digits(int x){//add_digits함수 선언

    int bef,sum,cnt=0;//정수형 변수 4개 선언
    int rst;//결과값 저장할 변수 선언
    while(cnt==0){//1차 반복
        sum =0;//정수의 각자리 합 변수를 0으로 초기화
        while(x>0){//n이 0보다 클때
            sum += x%10;//나머지 연산을 통해 각자리를 sum변수에 저장
            x /=10;//한자리수 씩 줄임
        }
        if(sum>=10){//sum이 두자리인경우
            x=sum;//sum을n으로 바꿔 재반복
        }
        else{//아닌 경우 cnt를 1로 바꿔 반복을 없애고 break
            cnt =1;
            break;
        }
    }
    //printf("error1\n");
    return sum;//결과값 반환

}

int main(){//메인 함수

    int num[100],rst;//입력받은 정수를 저장할 배열과 함수의 반환값을 저장할 변수 rst선언
    int min=1000000,result = -1;//최소를 초기화하고 디지털 근이 최소일때의 변수 저장 변수 선언

    int cnt = 0,k;//반복 횟수 cnt
    while(1){

        scanf("%d",&num[cnt]);//정수를 입력받아 배열에 저장
        k = num[cnt];// 배열 요소를 k에 저장
        if(k<0) break;//k가 음수이면 종료
        else cnt++;//아닌 경우 반복횟수 증가
        //printf("error2\n");
    }

    // printf("%d",cnt);
    // for(int i=0;i<cnt;i++){
    //     printf("<%d>",num[i]);
    // }
    for(int i=0;i<cnt;i++){//반복횟수 만큼 반복
        rst = add_digits(num[i]);//함수 실행
        //printf("%d\n",rst);
        if(rst<min){//결과값이 최솟값보다 작은 경우
            min  = rst;//min에 저장
            result = num[i];//최솟인 숫자를 저장
        }
    }
    printf("%d %d",result,min);//결과 출력
}