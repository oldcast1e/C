#include  <stdio.h>
int main(){
    
    int arr[5],cnt;//크기 5의 배열과 임의 실수 ㅌcnt선언
    int rank[5]={};//랭크를 저장할 배열 선언
    int *p = arr,*q=arr;//배열의 포인터를 2개 선언//큰 숫자의 개수를 구하기 위함
    for(p=arr;p<arr+5;p++){//5번 반복하여
        scanf("%d",p);//입력을 받음
    }

    int rn = 0;//랭크 요소값 초기화
    for(q=arr;q<arr+5;q++){//5번 반복하여
        cnt = 0;//해당값보다 큰 수의 개수 초기화
        for(p=arr;p<arr+5;p++)//다시 다섯번 반복
            if(*q<*p) cnt++;//크기가 큰 수가 있으면 증가
        rank[rn] = cnt+1;//반복이 끝나면 랭크배열에 cnt+1저장
        rn ++;//랭크 요솟ㄱ밧 증가
    }

    cnt =0 ;//cnt를 0으로 만듦
    for(p=arr;p<arr+5;p++){//5번 반복
        printf("%d=r%d ",*p,rank[cnt]);//배열의 요소와 랭크 배열의 요소를 출력
        cnt++;
    }
    
    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

