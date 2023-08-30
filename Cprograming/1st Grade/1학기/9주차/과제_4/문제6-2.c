#include  <stdio.h>
int main(){
    
    char ans[3],u,tmp;//문자 3개 저장할 크기 3의 char형 배열,입력받을 문자 그리고 엔터입력을 가질 빈 값 tmp 선언


    for(int i=0;i<3;i++){//3번 반복하여
        scanf("%c",&ans[i]);//문자를 입력받음
    }
    getchar();

    int cnt = 0,spn=0;//시도횟수 변수 cnt와 줄띄움 변수 spn
    int a=0,b=0,c=0;//3칸의 문자입력 정/오 분석 변수

    while(cnt<5){//시도한 횟수가 5미만인 경우 반복
        if(cnt==5)//시도횟수가 5이면 반복문 탈출
            break;

        scanf("%c",&u);//문자를 입력받음
        getchar();
        cnt ++;//시도횟수 증가

        if(u==ans[0])//배열의 첫번째 요소와 일치하는 경우
            a= 1;//a를 1로 만들어 일치함을 표시
        else if(u==ans[1])//배열의 두번째 요소와 일치하는 경우
            b=1;//b를 1로 만들어 일치함을 표시
        else if(u==ans[2])//배열의 세번째 요소와 일치하는 경우
            c=1;//c를 1로 만들어 일치함을 표시

        
        if(a==1 && b==0 && c==0){
            if(spn!=0)
                printf("\n");
            spn++;
            printf("%c _ _",ans[0]);//첫번째 요소만 출력
        }//첫번째 요소만 일치하는 경우
            
        else if(a==0 && b==1 && c==0){
            if(spn!=0)
                printf("\n");
            spn++;
            printf("_ %c _",ans[1]);//두번째 요소만 출력
        }//두번째 요소만 일치하는 경우
            
        else if(a==0 && b==0 && c==1){
            if(spn!=0)
                printf("\n");
            spn++;
            printf("_ _ %c",ans[2]);//세번째 요소만 출력
        }//세번째 요소만 일치하는 경우
            
        //3C1
        


        else if(a==1 && b==1 && c==0){
            if(spn!=0)
                printf("\n");
            spn++;
            printf("%c %c _",ans[0],ans[1]);//첫번째 요소와 두번째 요소만 출력
        }//첫번째 요소와 두번째 요소가 일치하는 경우
            
        else if(a==1 && b==0 && c==1){
            if(spn!=0)
                printf("\n");
            spn++;
            printf("%c _ %c",ans[0],ans[2]);//첫번째 요소와 세번째 요소만 출력
        }//첫번째 요소와 세번째 요소가 일치하는 경우
            
        else if(a==0 && b==1 && c==1){
            if(spn!=0)
                printf("\n");
            spn++;
            printf("_ %c %c",ans[1],ans[2]);//두번째 요소와 세번째 요소만 출력
        }//두번째 요소와 세번째 요소가 일치하는 경우
            
        //3C2


        else if(a==1 && b==1 && c==1){//입력값이 정답과 모두 일치하는 경우
            printf("%c %c %c",ans[0],ans[1],ans[2]);//모두 출력하고
            break;//반복 종료
        }

        else{
            if(spn!=0)
                printf("\n");
            spn++;
            printf("_ _ _");//빈값 출력
        }//아무것도 만족못한 경우
            
        
    }
}
