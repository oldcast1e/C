#include  <stdio.h>
int main() 
{
    int n;
    int a,b;//입력할 숫자와 숫자의 10의 자리 1의 자리를 담을 변수 선언
    scanf("%d",&n);//입력받음
    a = n/10;
    b = n%10;//ab에 각각의 자리를 대입
    if(20<=n && n<100){//20부터 99까지인 경우
        switch (a)
        {
            case 9://a가 9인경우, 10의 자리 영어를 지정
                printf("ninety");
            break;

            case 8://a가 8인경우
                printf("eighty");
            break;

            case 7://a가 7인경우
                printf("seventy");
            break;

            case 6://a가 6인경우
                printf("sixty");
            break;
        
            case 5://a가 5인경우
                printf("fifty");
            break;
            case 4://a가 4인경우
                printf("fourty");
            break;

            case 3://a가 3인경우
                printf("thirty");
            break;

            case 2://a가 2인경우
                printf("twenty");
            break;
        }
        if(b!=0)//일의 자리가 0이 아닌 경우 - 입력
                printf("-");
        switch (b)//b가 인경우
            {
            

            case 9://b가 9인경우
                printf("nine");
            break;

            case 8://b가 8인경우
                printf("eight");
            break;

            case 7://b가 7인경우
                printf("seven");
            break;

            case 6://b가 6인경우
                printf("six");
            break;
        
            case 5://b가 5인경우
                printf("five");
            break;
            case 4://b가 4인경우
                printf("four");
            break;

            case 3://b가 3인경우
                printf("three");
            break;

            case 2://b가 2인경우
                printf("two");
            break;
        
            case 1://b가 1인경우
                printf("one");
            break;//일의 자리를 더해줌
        
        }
    }
    else if(10<=n && n<20){//십의 자리가 1인 경우(영어에서는 십의 자리가 1인 경우가 다름)

        if(b==9)//b가 9인경우
                printf("nineteen");
        else if(b==8)//b가 8인경우
                printf("eighteen");
        else if(b==7)//b가 7인경우
                printf("seventeen");
        else if(b==6)//b가 6인경우
                printf("sixteen");
        else if(b==5)//b가 5인경우
                printf("fifteen");
        else if(b==4)//b가 4인경우
                printf("fourteen");
        else if(b==3)//b가 3인경우
                printf("thirteen");
        else if(b==2)//b가 2인경우
                printf("twelve");
        else if(b==1)//b가 1인경우
                printf("eleven");
        else if(b==0)//b가 0인경우
                printf("ten");
            
    }
    else if(n<=9 || n>=100)
            printf("none");//n의 1진 정수이거나 100진 정수 이상인경우 none 출력


}
