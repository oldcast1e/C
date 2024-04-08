#include  <stdio.h>

void gcdlcm(int x,int y,int *rs,int *rl){
    int small  = (x>y?y:x);
    int large = (x>y?x:y);

    int rstmax,rstmin;
    while(1){
        if(x%small==0 && y%small==0){
            rstmin = small;
            break;
        } 
        else small --;
        // printf("ploblem1\n");
    }
    while(1){
        if(large%x==0 && large%y==0){
            rstmax = large;
            break;
        } 
        else{
            large ++;
            // printf("ploblem2:%d\n",large);
        } 
    }
    *rl=rstmax;
    *rs = rstmin;
    // printf("%d %d",*rs,*rl);
}
int main(){
    int x,y,*rs=&x,*rl=&y;
    scanf("%d %d",&x,&y);
    gcdlcm(x,y,rs,rl);
    printf("%d %d",*rs,*rl);
    
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//두 정수를 입력받아 최대 공약수와 최소공배수를 포인터를 사용하여 전달하는 프로그램
