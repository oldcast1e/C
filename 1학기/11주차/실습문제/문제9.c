#include  <stdio.h>

int max1,max2,cnt=0;//전역변수 max1,max2선언,첫번째 반복시 max1,2값을 초기화할때 사용할 조건값 cnt선언

void update_max(int x){//update_max함수 정의
    
    if(cnt==1){//cnt가 1인 경우(예외적 상황):숫자가 두번 나온 상황에서 첫번째 값보다 두번째 값이 작으면 두번째 값을 max2로 첫번째 값을 max1으로 저장
        if(x>max1){//x가 max1보다 큰 경우
            max1  = x;//max2는 그대로 max1만 업데이트
        }
        else
            max2 = x;//아닌 경우(x가 max1(max2)보다 작은 경우),max1은 그대로 두고 max2에 x 저장    
    }
    else{
        if(x>max1){//입력받은 x값이 max1보다 큰 경우(ㄱ)
            max2 = max1;// max2에 max1을 저장하고
            max1 = x;//max1에 x를 저장
        }
        else if(max1>=x && x>=max2){//ㄱ 경우가 아니며,max1이 x보다 크거나 같고 x가 max2보다 크거나 같은 경우
            max2 = x;//max2에 x를 저장
    }
    }

    
    
}
int main(){//main 함수 
    
    int n;//입력받을 변수 n
   
    while(1){//무한 반복
        scanf("%d",&n);//n을 입력받거
        if(n==0)//n이 0이면 종료(종료조건)
            break;//종료

        if(cnt==0){//cnt=0일때
            max1 = n;//max1,2를 n으로 초기화
            max2 = n;
        }
        else
            update_max(n);//update_max 함수 실행

        cnt++;//cnt증가
    }
    printf("%d %d",max1,max2);//최대,두번째 최대값 출력


}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
