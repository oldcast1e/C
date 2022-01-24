#include  <stdio.h>
int main(){
    int a[11],b[11],*pa = a,*pb = b,n=0,m=0;
    int max,min,tmp,key = 1;

    int cmax,cmin;
    while(1){
        scanf("%d",(pa+n));
        if(*(pa+n)==0)break;
        n ++;
    }
    while(1){
        scanf("%d",(pb+m));
        if(*(pb+m)==0)break;
        m ++;
    }


    /////
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
    }///////내림차 순서로 재배열
    max  = *pa>*pb?*pa:*pb;
    min = *(pa+n-1)<*(pb+m-1)?*(pa+n-1):*(pb+m-1);

    printf("n = %d | m = %d\n",n,m);
    for(int i=0;i<n;i++)printf("%d ",*(pa+i));printf("\n");
    for(int i=0;i<m;i++)printf("%d ",*(pb+i));printf("\n\n");

    for(int i=0;i<n;i++){//n개의 오름차순 나열
        printf("%d ",max);
        key = 1;
        while(key == 1){
            if(*(pa+i)>*(pb+i)){
                for(int j = 0;j<n;j++){
                    if(max> *(pa+j)){
                        cmax  = *(pa+j);
                        key  = 0;
                        break;
                    }
                }
                for(int j = 0;j<m;j++){
                    if(cmax> *(pb+j)){
                        cmax  = *(pb+j);
                        key  = 0;
                        break;
                    }
                }
            }
            else{
                for(int j = 0;j<m;j++){
                    if(cmax> *(pb+j)){
                        cmax  = *(pb+j);
                        key  = 0;
                        break;
                    }
                }
                for(int j = 0;j<n;j++){
                    if(max> *(pa+j)){
                        cmax  = *(pa+j);
                        key  = 0;
                        break;
                    }
                }
            }
            
        }
        for(int k = 0;k<n;k++)if(*(pa+k)>cmax && max > *(pa+k)) cmax = *(pa+k);
        for(int k = 0;k<m;k++)if(*(pa+k)>cmax && max > *(pa+k)) cmax = *(pa+k);
        max = cmax;
    }

    printf("\n");
    for(int i=0;i<m;i++){//m개의 내림차순 나열
        printf("%d ",min);
        key = 1;
        while(key == 1){
            for(int j = 0;j<n;j++){
                if(min <= *(pa+j)){
                    cmin  = *(pa+j);
                    key  = 0;
                    break;
                }
            }
            if(key == 0) break;
            for(int j = 0;j<m;j++){
                if(min <= *(pb+j)){
                    cmin  = *(pb+j);
                    key  = 0;
                    break;
                }
            }
        }
        for(int k = 0;k<n;k++)if(*(pa+k) < cmin && min < *(pa+k)) cmin = *(pa+k);
        for(int k = 0;k<m;k++)if(*(pb+k) < cmin && min < *(pb+k)) cmin = *(pb+k);
        min = cmin;
    }
}
//두 개의 뱡ㄹ에 정수를 입력받고 이를 적절히 정렬하는 프로그램을 작성하라

//0이 들어오기전까지 각 배열에 숫자를 입력받고, n,m은 최소 1이며 최대 10이다.
//입력되는 정수의 개수 n,m은 입력으로 주어지지 않는다.
//배열에 a에는 배열에 a,b에 저장된 정수들 중 가장 큰 n개를 내림차순으로 저장
//배열에 b에는 배열에 a,b에 저장된 정수들 중 가장 큰 m개를 오름차순으로 저장

//다른 배열은 사용할 수 없다.

//-10 20 40 -5 10 0
//-100 200 -50 -15 -5 0

//100 20 90 30 20 100 200 40 50 10 0
//5 55 85 105 205 5 15 55 25 45 0