#include  <stdio.h>

int S,E,N,M,spn=0;//입력받을 S,E,N,M과 줄띄움 전역변수 선언
int SumMultiple(int Start,int End,int X);//함수원형 선언

int main(){//main함수 정의
    
    scanf("%d %d %d %d",&S,&E,&N,&M);//4개의 값을 입력받고
    int k = SumMultiple(S,E,N);//SumMultiple함수 실행
}
int SumMultiple(int Start,int End,int X){//3개의 인자 대입

    int sum,cnt;//합 변수와 합변수에 대입할 임의의 변수 cnt선언
    for(int j=0;j<6;j++){//6번 반복하여
        cnt =0;//cnt를 0으로 초기화(반복해서 사용)
        for(int i=S;i<E;i++){
            if(j==0){//S 이상 E 미만의 정수 중 N의 배수의 합
                if(i%X==0) cnt += i;
            }
            else if(j==1){//S 이상 E 미만의 정수 중 M의 배수의 합
                if(i%M==0) cnt+= i;
            }
            else if(j==2){//S 이상 E 미만의 정수 중 N의 배수이면서 M의 배수인 수의 합
                if(i%X==0 && i%M==0) cnt+= i;
            }
            else if(j==3){//S 이상 E 미만의 정수 중 N의 배수이거나 M의 배수인 수의 합
                if(i%X==0 || i%M==0) cnt+= i;
            }
            else if(j==4){//S 이상 E 미만의 정수 중 M의 배수이면서 N의 배수가 아닌 수의 합
                if(i%X!=0 && i%M==0) cnt+= i;
            }
            else if(j==5){//S이상E미만의정수중N의배수도M의배수도아닌수의합
                if(i%X!=0 && i%M!=0) cnt+= i;
            }
            
        }
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        
        printf("%d",cnt);//cnt합 출력(결과값)
    }

    return 0;
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가

