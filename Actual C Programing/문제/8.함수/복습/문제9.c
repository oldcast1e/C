#include  <stdio.h>
int max1,max2;
void update_max(int x){
    if(x>max1){
        max2 = max1;
        max1 = x;
    }
    else if(max1>=x && x>max2) max2 = x;

}
int main(){
    int num,cnt=0;
    while(1){
        scanf("%d",&num);
        if(num==0) break;
        if(cnt<2){
            if(cnt==0) max1 = num;
            if(cnt==1) update_max(num);
            cnt++;
        }
        else update_max(num);
    }
    printf("%d %d",max1,max2);
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

