#include  <stdio.h>
struct vec//구조체 정의
{   
    int x,y,z;//3차원 벡터정의
    /* data */
};

int main(){
    struct vec v1;//구조체 변수 선언
    struct vec v2;//구조체 변수 선언
    int v3;//내적값 정의
    scanf("%d",&v1.x);
    scanf("%d",&v1.y);
    scanf("%d",&v1.z);//3차원 벡터를 입력받음

    scanf("%d",&v2.x);
    scanf("%d",&v2.y);
    scanf("%d",&v2.z);//3차원 벡터를 입력받음

    printf("%d %d %d\n",v1.x*v2.x, v1.y*v2.y, v1.z*v2.z);
    //v3출력
    v3 = (v1.x*v2.x + v1.y*v2.y+ v1.z*v2.z);//내적값 계산
    printf("%d",v3);//출력
    

}