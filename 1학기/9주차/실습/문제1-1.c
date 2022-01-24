#include  <stdio.h>
int main(){
    
    int x[5],sum=0,cnt=0;//배열과 합,카운트 변수 선언
    double avg=0.0;//평균 변수 선언
    for(int i=0;i<5;i++){//5번 반복하여
        scanf("%d",&x[i]);//배열의 요소를 입력받음
    }
    for(int i=0;i<5;i++){
        sum += x[i];//5번 반복하여 sum 변수에 더함
    }
    avg = (double)sum/5;//평균을 냄

    for(int i=0;i<5;i++){
        if(x[i]>avg){//해당 요소가 평균보다 크면
            
            if(cnt!=0)//cnt가 0이 아닐때
                printf("\n");//줄을 바꾸고
            cnt++;
            printf("%d",x[i]);//결과값을 출력함
        }
        
        
    }

}


