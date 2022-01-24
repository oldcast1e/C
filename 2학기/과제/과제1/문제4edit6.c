#include<stdio.h>
int main(){
    int a[11]={0},b[11]={0},*pa = a,*pb = b;//크기 10인 배열 a,b선언 및 포인터 연결
    int n=0,m=0,tmp;//길이 저장 변수 n,m 그리고 값을 바꿀 임의의 값 tmp 선언

    while(1){//무한 반복
        scanf("%d",(pa+n));//배열 a에 입력을 받음
        if(*(pa+n)==0)break;//0을 입력받으면 종료
        n ++;//길이 증가
    }
    while(1){
        scanf("%d",(pb+m));//배열 b에 입력을 받음
        if(*(pb+m)==0)break;//0을 입력받으면 종료
        m ++;//길이 증가
    }
    for(int i = 0;i<n;i++){//a의 길이 만큼 반복
        for(int j = 0;j<n;j++){//해당 길이 만큼 반복
            if(i < j){//자신의 순서보다 뒤인 요솟값 부터
                if(*(pa + j) > *(pa + i)){// 해당 요소보다 큰 경우

                    tmp = *(pa + i);
                    *(pa + i) = *(pa + j);
                    *(pa + j) = tmp;//해당자리와 값을 바꿈
                }
            }     
        }
        // printf("\n1.");
        // for(int i = 0;i<n;i++)printf("%d ",*(pa+i));
        // printf(" 2. ");
        for(int k = 0;k<m;k++){//b의 길이 만큼 반복
            if(*(pb + k) > *(pa + i)){// 해당 요소보다 큰 경우
                tmp = *(pa + i);
                *(pa + i) = *(pb + k);
                *(pb + k) = tmp;//해당자리와 값을 바꿈
            }
        }
        // for(int i = 0;i<n;i++)printf("%d ",*(pa+i));
    }
    /////////////////////
    for(int i = 0;i<m;i++){//b의 길이 만큼 반복
        for(int j = 0;j<m;j++){//b의 길이 만큼 반복
            if(i < j){//자신의 순서보다 뒤인 요솟값 부터
                if(*(pb + j) < *(pb + i)){// 해당 요소보다 작은 경우

                    tmp = *(pb + i);
                    *(pb + i) = *(pb + j);
                    *(pb + j) = tmp;//해당자리와 값을 바꿈
                }
            }
                
        }
        // printf("\n1.");
        // for(int i = 0;i<n;i++)printf("%d ",*(pa+i));
        // printf(" 2. ");
        for(int k = 0;k<n;k++){//a의 길이 만큼 반복
            if(*(pa + k) < *(pb + i)){
                tmp = *(pb + i);
                *(pb + i) = *(pa + k);
                *(pa + k) = tmp;//해당자리와 값을 바꿈
            }
        }
    }
    for(int i = 0;i<n;i++)printf("%d ",*(pa+i));//바꾼 배열 a출력
    printf("\n");
    for(int i = 0;i<m;i++)printf("%d ",*(pb+i));//바꾼 배열 b출력
}

//100 20 90 30 20 100 200 40 50 10 0
//5 55 85 105 205 5 15 55 25 45 0