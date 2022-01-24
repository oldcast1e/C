#include  <stdio.h>
int main() 
{
    int a,b,c;
    int sum = 0;
    scanf("%d %d %d",&a,&b,&c);
    sum = (a+b+c)/3;
    int max = -1,min=-1;

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



    //점수가 같은 경우를 생각해야함
    if(a==b && b==c){//모두 같은 경우)
        max = a;
        min = a;
    }
    
    else if(a!=b && a!=c && b!=c){//점수 3개가 모두 다른경우

        if(a>b && a>c)
            max = a;//a가 가장 크면 최댓값에 a를 대입
        else if(b>a && b>c)
            max = b;//b가 가장 크면 최댓값에 b를 대입
        else if(c>a && c>b)
            max = c;//b가 가장 크면 최댓값에 b를 대입

        if(a<b && a<c)
            min = a;//a가 가장 작으면 최솟값에 a를 대입
        else if(b<a && b<c)
            min = b;//b가 가장 작으면 최솟값에 b를 대입
        else if(c<a && c<b)
            min = c;   //c가 가장 작으면 최솟값에 c를 대입
   

    }
    else if((a==b)&& a!=c || (a==c)&&a!=b || (b==c)&&b!=a){//두개만 같은 경우

        if(a==b){//a와 b가같은 경우
            max = (a>c?a:c);
            min = (a<c?a:c);//a와 b가 같은 경우는 a와 c만 비교
        }
        else if(a==c){//a와 c가같은 경우
            max = (a>b?a:b);
            min = (a<b?a:b);//a와 c가 같은 경우는 a와 b만 비교
        }
        else if(b==c){//c와 b가같은 경우
            max = (b>a?b:a);
            min = (b<a?b:a);//c와 b가 같은 경우는 c와 a만 비교
        }


    }
    printf("max: %d\n",max);
    printf("min: %d",min);//최대,최소 출력   


    
}