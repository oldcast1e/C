#include  <stdio.h>

int N,spn = 0;//전역변수 N과 spn(줄띄움 변수)선언
void die3(int x,int y,int z){//die3함수 정의
    
    if((x+y+z)==N){//3개의 인자의 합이 N인 경우
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        printf("%d %d %d",x,y,z);//각각의 인자 출력
    }
        
}
void die2(int x,int y){//die2 함수 정의
    
    for(int k =1;k<=6;k++){//6번 반복하여
        die3(x,y,k);//die3함수 실행
    }
}

void die1(int x){//die1 함수 정의

    int a  = x;//x를 a에 저장
    for(int j =1;j<=6;j++){//6번 반복하여
        die2(a,j);//die2함수 실행
    } 
}

int main(){//main함수
    
    scanf("%d",&N);//N을 입력받아
    for(int i =1;i<=6;i++){//6번 반복하여
        die1(i);//die1함수 실행
    }

    
}


