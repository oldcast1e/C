#include  <stdio.h>
int main(){
    int a[11],b[11],*pa = a,*pb = b ;
    int n,m,max,min,chmax,chmin,tmp;
    int cnta = 0,cntb = 0;
    while(1){//배열 a입력
        scanf("%d",(pa + cnta));
        if(*(pa + cnta)==0)break;
        cnta ++;
    }
    while(1){//배열 b입력
        scanf("%d",(pb + cntb));
        if(*(pb + cntb)==0)break;
        cntb ++;
    }
    n= cnta,m = cntb;
    for(int k=0;k<2;k++){//첫번째 최대값 구하기
        if(k==0){
            for(int i=0;i<n;i++){
                if(i==0)max= *(pa+i);
                else if(*(pa+i)>max) max = *(pa+i);
            }
        }
        else for(int i=0;i<m;i++)if(*(pb+i)>max) max = *(pb+i);  
    }
    ////
    for(int k=0;k<2;k++){//두번째 최대값 구하기
        if(k==0){
            for(int i=0;i<n;i++){
                if(i==0)min= *(pa+i);
                else if(*(pa+i)<min) min = *(pa+i);
            }
        }
        else for(int i=0;i<m;i++)if(*(pb+i)<min) min = *(pb+i);
    }
    /////배열 a,b 내림차순으로 정렬
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(*(pa+i) > *(pa+j)){
                    tmp = *(pa+i);
                    *(pa+i) = *(pa+j);
                    *(pa+j) = tmp;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i!=j){
                if(*(pb+i) > *(pb+j)){
                    tmp = *(pb+i);
                    *(pb+i) = *(pb+j);
                    *(pb+j) = tmp;
                }
            }
        }
    }
    //////
    // for(int i=0;i<n;i++)printf("%d ",*(pa+i));
    // printf("\n");
    // for(int i=0;i<m;i++)printf("%d ",*(pb+i));
    /////내림차순으로 n개, 오름차순으로 m개
    for(int k=0;k<n;k++){
        if(k==0){
            printf("%d",max);
            for(int i=0;i<n;i++){
                if(i==0)chmax = *(pa+i);
                else{
                    if(max>*(pa+i) && *(pa+i)>chmax) chmax = *(pa+i);
                }
            }       
        }
        else for(int i=0;i<m;i++){
            if(max>*(pb+i) && *(pb+i)>chmax) chmax = *(pb+i);   
        }
        max = chmax;
    }
    


}
//두 개의 뱡ㄹ에 정수를 입력받고 이를 적절히 정렬하는 프로그램을 작성하라

//0이 들어오기전까지 각 배열에 숫자를 입력받고, n,m은 최소 1이며 최대 10이다.
//입력되는 정수의 개수 n,m은 입력으로 주어지지 않는다.
//배열에 a에는 배열에 a,b에 저장된 정수들 중 가장 큰 n개를 내림차순으로 저장
//배열에 b에는 배열에 a,b에 저장된 정수들 중 가장 큰 m개를 오름차순으로 저장

//다른 배열은 사용할 수 없다.