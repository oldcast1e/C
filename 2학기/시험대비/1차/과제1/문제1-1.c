#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int MAX(int *ar);
int MIN(int *ar);

int main(){

    int N,cnt=0;;
    int ar[100],*par = ar;

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        while(1){
            scanf("%d",(par+cnt));
            if(*(par+cnt)==0)break;
            cnt++;
        }
        
        printf("%d %d\n",MAX(ar),MIN(ar));
        // for(int j=0;j<cnt;j++){
        //     printf("<%d>",*(par+j));
        // }
        // printf("\n");
        cnt = 0;
    }


}

/*
입력될 줄 수에 해당하는 정수 N을 입력받는다. 
각 줄에서 0 이 입력 될 때까지만 정수를 입력받는다. 
각 줄에서 0 이후에는 숫자가 없다. 각 줄에서 0은 두 번째부터 입력될 수 있다. 
각 줄에서 0을 제외한 최대값과 최소값을 출력하시오
*/

int MAX(int *ar){
    int rst,max;
    max = *(ar+0);
    // printf("max1 = %d\n",max);
    for(int i=1; ;i++){
        if(*(ar+i)==0)break;

        if(*(ar+i) > max){
            max  = *(ar+i);
        }
    }

    return max;
}
/*
1) MAX( ) 함수 이용
- 인자: int형 배열 ar
- 배열 표기 [ ] 사용금지
- 배열에서 최대값의 주소를 반환한다. - 반환 값: int형 포인터 즉 주소
*/

int MIN(int *ar){
    int rst;
    int min = *(ar+0);

    for(int i=1; ;i++){
        if(*(ar+i)==0)break;
        if(*(ar+i) < min){
            min  = *(ar+i);
        }
    }

    return min;
    
}
/*
2) MIN( ) 함수 이용
- 인자: int형 배열 ar
- 배열 표기 [ ] 사용금지
- 배열에서 최소값의 주소를 반환한다. - 반환 값: int형 포인터 즉 주소
*/

/*
3
3 7 6 -2 0
1 7 6 13 2 0
2 0


*/