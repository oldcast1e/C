#include  <stdio.h>
int main(){
    int a[11],b[11],*pa = a,*pb = b ;
    int n,m,max,min,tmp,cmax,cmin;
    int maxcnt = 0,mincnt = 0;
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
    printf("---------\n");
    for(int i=0;i<n;i++)printf("%d ",*(pa+i));
    printf("\n");
    for(int i=0;i<m;i++)printf("%d ",*(pb+i));
    printf("\n");
    printf("---------\n");

    max = *pa>*pb?*pa:*pb;
    min = *(pa+n-1) < *(pb+m-1) ? *(pa+n-1) : *(pb+m-1);

    for(int p = 0;p<n;p++){
        printf("%d ",max);
        if(*pa>*pb){//a배열 먽저 --- 최댓값
            for(int i=1;i<n;i++){
                if(i==1)cmax = *(pa+i);
                else if(max > *(pa+i) && *(pa+i)>cmax) cmax  =*(pa+i);
            }
            for(int i=0;i<m;i++){
                if(max > *(pb+i) && *(pb+i)>cmax) cmax  =*(pb+i);
            }
        }
        else{
            for(int i=1;i<m;i++){
                if(i==1)cmax = *(pb+i);//20
                else if(max > *(pb+i) && *(pb+i)>cmax) cmax  =*(pb+i);
            
            }
            for(int i=0;i<n;i++){
                if(max > *(pa+i) && *(pa+i)>cmax) cmax  =*(pa+i);
            }
        }
        max = cmax;
    }
    ////////////////////////////////////
    printf("\n");
    for(int p = 0;p<m;p++){
        printf("%d ",min);
        if(*(pa+n-1) < *(pb+m-1)){//a배열의 마지막값이 더 작으면 
            for(int i=n-2;i>=0;i--){ //n-cntdid
                if(i==(n-2))cmin = *(pa+i);
                else if(min < *(pa+i) && *(pa+i) < cmin) cmin  = *(pa+i);
            }
            for(int i=m-2+1;i>=0;i--){
                if(min < *(pb+i) && *(pb+i) < cmin) cmin  = *(pb+i);
            }
            printf("rep1 cmin = %d\n",cmin);
        }
        else{
            for(int i=m-2;i>=0;i--){
                if(i==(m-2))cmin = *(pb+i);//20
                else if(min < *(pb+i) && *(pb+i) < cmin){
                    cmin  =*(pb+i);
                    break;
                } 
            }

            for(int i=n-2+1;i>=0;i--){
                if(min < *(pa+i) && *(pa+i) < cmin){
                    cmin  =*(pa+i);
                    break;
                } 
            }
            printf("\ncmin = %d | min = %d\n",cmin,min);
           
            min = cmin;
        }
        
    }
    


}
//50 10 70 0
//100 20 0

//-10 20 40 -5 10 0
//-100 200 -50 -15 -5 0
