#include  <stdio.h>
int max1,max2;
int update_max(int x){

    if(x>max1){
        max2 = max1;
        max1 = x;
    }
    if(max1>=x && x>max2){
        max2 = x;
    }
    return 0;
}
int main(){
    
    int n,cnt=0;

    while(1){
        scanf("%d",&n);
        if(n==0) break;

        if(cnt==0) max1 = n,max2 = n;
        cnt ++;
        update_max(n);
    }
    printf("%d %d",max1,max2);
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

