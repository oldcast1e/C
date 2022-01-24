#include  <stdio.h>
int main(){
    int x, y, z,t=0;//4개의 값(정수형변수) 선언
    int *px = &x, *py=&y, *pz=&z, *tmp = &t ; //각각의 포인터 선언 tmp는 포인터이다
    scanf("%d %d %d",&x,&y,&z);//3변수를 입력받아 저장
    *tmp = *px;//x의 포인터 값을 저장

    *px = *pz;//값 이동
    *pz = *py;//값 이동
    *py = *tmp;//값 이동
    printf("%d %d %d",*px,*py,*pz);//결과값 출력
}