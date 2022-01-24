#include  <stdio.h>
int main(){

    int arr[5]={0},rst[5]={0};//크기5의 배열 선언(입력받을 배열,결과값 저장 배열)
    int *pnum = arr,cnt;//배열의 포인터 선언 및 내림차순 순서를 저장할 변수 cnt선언
    for(int i=0;i<5;i++){//5번 반복하여 입력받음
        scanf("%d",(pnum+i));
    }
    for(int i=0;i<5;i++){//5번 반복하여
        cnt = 0;//변수 초기화
        for(int j=0;j<5;j++){//5번 반복하여
            if(*(pnum+i)!=*(pnum+j)){//두 해당 배열요소가 같지 않을때
                // printf("i=%d j=%d\n",i,j);
                if(*(pnum+i) < *(pnum+j)){//*(pnum+j)가 더 큰게 존재할 경우 cnt증가
                    cnt ++;
                    // printf("j = %d pi=%d pj=%d\n",j,*(pnum+i), *(pnum+j));
                } 
            }
        }
        *(rst+i) = cnt+1;//해당 배열에 순위 저장
    }
    for(int i=0;i<5;i++){//5번 반복하여
        printf("%d=r%d ",*(pnum+i),*(rst+i));//결과값 출력
    }

}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
//1보다 큰 수가 4/6보다 큰수가 1개/4보다 큰수가 3/9보다 큰 수 0
// 1 -> 5 / 6 -> 2 / 4 -> 4 / 9 -> 1