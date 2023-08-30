#include  <stdio.h>

int add(int x){//add 함수 선언

    int sum=0;//합을 뜻하는 sum변수 선언
    for(int i=1;i<=x;i++){//인자 만큼 반복하여
        sum+=i;//sum에 더함
    }
    return sum;//sum값 반환
}

int main(){// main함수
    
    int n,rst;//입력받을 정수과 결과값 변수 선언
    scanf("%d",&n);//n을 입력받아

    rst  = add(n);//add함수 실행 후 반환된 값을 rst값에 저장
    printf("%d",rst);//결과값 출력

}

// if(spn!=0)
//             printf("\n");
//         spn++;
