#include  <stdio.h>

int main() 
{
   int a,b,c;
   int sum=0;//정수 3개와 합 변수 선언
   int max,min;// 최댓값,최솟값 선언
   scanf("%d %d %d",&a,&b,&c);
   sum = (a+b+c)/3;//값 3개를 입력받고 평균을 구해 sum변수에 넣음

   if(sum>=90){
        printf("A\n");//평균이 90이상이면 A
   
   }
   else if(sum>=80){
       printf("B\n");//평균이 80이상이면 B
   }
   else if(sum>=70){
       printf("C\n");//평균이 70이상이면 C
   }
   else if(sum>=60){
       printf("D\n");//평균이 60이상이면 D
   }
   else
    printf("F\n");//위 조건을 모두 만족하지 않는 경우(60점 미만) F
    //각각의 조건문은 위에서 부터 순차적으로 진행되고 만족하는 경우 수행,
    //만족하지 않는 경우 수행하지않고 내려오므로 각각의 조건문은 하나의 조건만 있어도 된다.

    if(a>b && a>c)
            max = a;//a가 가장 크면 최댓값에 a를 대입
    else if(b>a && b>c)
            max = b;//b가 가장 크면 최댓값에 b를 대입
    else if(c>a && c>b)
            max = b;//b가 가장 크면 최댓값에 b를 대입

    if(a<b && a<c)
            min = a;//a가 가장 작으면 최솟값에 a를 대입
    else if(b<a && b<c)
            min = b;//b가 가장 작으면 최솟값에 b를 대입
    else if(c<a && c<b)
            min = c;   //c가 가장 작으면 최솟값에 c를 대입
    printf("max: %d\n",max);
    printf("min: %d",min);//최대,최소 출력






}