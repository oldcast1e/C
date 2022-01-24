#include  <stdio.h>
void input(int *px,int *py,int *pz){
    scanf("%d %d %d",px,py,pz);
    
}
void output(int *px,int *py,int *pz){
    printf("%d %d %d",*px,*py,*pz);
}
int main(){

    int x,y,z;
    int *px = &x,*py = &y,*pz = &z;
    input(px,py,pz);
    output(px,py,pz);


}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
