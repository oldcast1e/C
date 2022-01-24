#include  <stdio.h>
int main() 
{
   int n,m,k;
   int sum;//메뉴 번호 3개 정의, 총 금액 변수 선언
   scanf("%d %d %d",&n,&m,&k);//각각의 번호를 입력받음
   if(n==1){//첫번째 번호가 1인경우
       sum += 15000;//총금액에 15000을 더하고 메뉴를 출력
       printf("Pizza\n");
    }
    else if(n==2){//첫번째 번호가 1인경우
        sum += 5000;
        printf("Burger\n");//총금액에 5000을 더하고 메뉴를 출력
    }
    else if(n==3){//첫번째 번호가 2인경우
        sum += 4500;
        printf("Salad\n");//총금액에 4500을 더하고 메뉴를 출력
    }
    else if(n==4){//첫번째 번호가 3인경우
        sum += 800;
        printf("Ice cream\n");//총금액에 800을 더하고 메뉴를 출력
    }
    else if(n==5){//첫번째 번호가 4인경우
        sum += 500;
        printf("Beverage\n");//총금액에 500을 더하고 메뉴를 출력
    }
    else if(n==0)  //첫번째 번호가 0인경우
        printf("None\n");//None을 출력


    if(m==1){//두번째 번호가 1인경우
       sum += 15000;//총금액에 15000을 더하고 메뉴를 출력
       printf("Pizza\n");
    }
    else if(m==2){//두번째 번호가 2인경우
        sum += 5000;//총금액에 5000을 더하고 메뉴를 출력
        printf("Burger\n");
    }
    else if(m==3){//두번째 번호가 3인경우
        sum += 4500;//총금액에 4500을 더하고 메뉴를 출력
        printf("Salad\n");
    }
    else if(m==4){//두번째 번호가 4인경우
        sum += 800;//총금액에 800을 더하고 메뉴를 출력
        printf("Ice cream\n");
    }
    else if(m==5){//두번째 번호가 5인경우
        sum += 500;//총금액에 500을 더하고 메뉴를 출력
        printf("Beverage\n");
    }
    else  if(m==0) //두번째 번호가 0인경우
        printf("None\n");//None을 출력
    
    if(k==1){//세번째 번호가 1인경우
       sum += 15000;//총금액에 15000을 더하고 메뉴를 출력
       printf("Pizza\n");
    }
    else if(k==2){//세번째 번호가 2인경우
        sum += 5000;//총금액에 5000을 더하고 메뉴를 출력
        printf("Burger\n");
    }
    else if(k==3){//세번째 번호가 3인경우
        sum += 4500;//총금액에 4500을 더하고 메뉴를 출력
        printf("Salad\n");
    }
    else if(k==4){//세번째 번호가 4인경우
        sum += 800;//총금액에 800을 더하고 메뉴를 출력
        printf("Ice cream\n");
    }
    else if(k==5){//세번째 번호가 5인경우
        sum += 500;//총금액에 500을 더하고 메뉴를 출력
        printf("Beverage\n");
    }
    else  if(k==0) //세번째 번호가 0인경우
        printf("None\n");//None을 출력

    printf("Total:%dwon",sum);//마지막으로 총 금액 출력

    
    




}