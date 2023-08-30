#include  <stdio.h>

int sum(int x){

    int cnt = 1;
    double sum = 0;//반복횟수를 증가할 변수 cnt와 합을 저장할 변수 sum 선언

    for(int i=1;i<=x;i++){//입력된 x만큼 반복(ㄱ)

        sum += i*(i+1)/2;//문제2와 같은 공식을 이용하여 sum값에 더함
    }
    return sum;//sum값을 반환
}
int main(){//main함수
    
    int n,rst;//입력받을 n과 결과값 rst를 선언
    scanf("%d",&n);//n을 입력받고,
    rst = sum(n);//sum함수를 호출
    
    printf("%d",rst);//반환된 값을 출력(결과값)
}

// if(spn!=0)
//             printf("\n");
//         spn++;
