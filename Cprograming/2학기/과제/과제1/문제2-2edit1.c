#include <stdio.h>
int passengerN(int n){
    int psgnum;
    if(n>5) psgnum = 0;
    else psgnum = -1;
    return psgnum;
}
int rebooking(int *ar){
    int *i,*j,tmp[21],*ptmp=tmp;
    for(int i=0;i<21;i++)(*(ptmp+i) = i+1);
    for (i=ar;i<ar+21;i++){
        
    }
    for (i=ar;*i!=0;i++){ 
        for (j=ar;j<i;j++){ 

            if(*i == *j){
                for(int k=0;k<21;k++){
                    if(*i != *(ptmp+k)){};
                }
            }
        }
    }

    return 0;
}
int changeseat(int *pnum){
    return 0;
}
int main(){
    int N,cnt,repval,arr[21]={0},*pnum = arr;
    int ovr[21] = {0}, *povr = ovr;

    // int rbk[21],*prbk = rbk;//예약을 확인하여 중복이 발생한 경우 미 예약된 숫자중 가장 적은 숫자를 판별
    // for(int i=0;i<21;i++) *(rbk+i) = i+1;

    scanf("%d",&N);
    for (int i = 0; i < N; i++)scanf("%d", (pnum + i));
    repval = (passengerN(N)==0?1:-1);
    printf("%d\n",passengerN(N));
    if(repval == 1){
        for (int i=0;i<N;i++){ //N번 반복하여....ㄱ
            for (int j=0;j<N;j++){ //N번 반복하여(2).....ㄴ
                if (*(pnum+i)==*(pnum+j))*(povr+i)+=1; //중복을 저장하는 변수의 요소값을 1증가//ㄱ과 ㄴ의 요소가 같으면
            }
        }
        for (int i=0;i<N;i++){
            if(*(povr+i)>1){//중복이면,
                rebooking(arr);

            }
        }
    }

    // printf("rbk: ");
    // for (int i = 0; i < N; i++)printf("%d", *(rbk + i));
    // printf("\n");
    // printf("arr: ");
    // for (int i = 0; i < N; i++)printf("%d", *(arr + i));
    // printf("\n");

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         if(*(rbk+i)==*(arr+j)){
    //             *(rbk+i) = 0;
    //             break;
    //         } 
    //     }
    // }

    // for (int i = 0; i < N; i++)printf("%d", *(rbk + i));
    // printf("%d",passengerN);
    // if(passengerN == 0){




    
}