#include  <stdio.h>
int main(){
    int  x,y,z,tmp;
    int *px = &x,*py = &y,*pz = &z;
    scanf("%d %d %d",px,py,pz);
    tmp = *pz;
    *pz = *py;
    *py = *px;
    *px = tmp;
    printf("%d %d %d",*px,*py,*pz);





}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
