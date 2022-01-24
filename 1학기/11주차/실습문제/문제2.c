#include  <stdio.h>

int add2(int x ,int y){//x값 부터 y값까지 더하는 함수 정의 

    double sum  = y*(y+1)/2 - (x-1)*x/2;//1부터 n까지의 합인 n(n+1)/공식이용하여 sum에 저장
    //예를 들어4,8이면 1~8까지의 합과 1~3까지의 합을 빼서 계산

    return sum;//sum 값을 반환

}
int main(){//maingkatn
    
    int A,B,rst;//입력받을 값인 A,B 값과 결과값 rst선언
    scanf("%d %d",&A,&B);//A,B를 입력받음
    rst = add2(A,B);//함수에 A,B를 실행 후 반환값을 rst에 저장

    printf("%d",rst);//결과값 출력

}

// if(spn!=0)
//             printf("\n");
//         spn++;
