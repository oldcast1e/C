#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
void pswap(int **ppx,int **ppy ){//변수에 저장된 주소를 바꾸는 함수 pswap( )
    // printf("before: %p %p\n",*ppx,*ppy);
    int *tmp;
    tmp = *(ppx);
    *ppx = (*ppy);
    *ppy = tmp;
    // printf("after: %p %p",*ppx,*ppy);
}
int main(){
    int x,y,*px = &x,*py = &y;
    // int형 변수 두 개 x, y와 두 변수를 가리키는 포인터 px, py를 선언
    int **ppx = &px,**ppy = &py;
    scanf("%d %d",&x,&y);
    // px의 주소와 py의 주소를 실인자로 하는, 함수 pswap( )을 호출
    pswap(ppx,ppy);//함수 실행
    printf("%d %d",*px,*py);//결과출력


}