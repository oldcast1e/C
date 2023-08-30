#include  <stdio.h>
int main(){
    
    int n,m,rep,stn;//덧셈 연산의 최적화
    int rst = 0,cnt=0;
    scanf("%d %d",&n,&m);
    int a = (n>0?n:n*-1);// n 의 절대값
    int b = (m>0?m:m*-1); //m의 절대값

    if(n*m>0){//부호 같음
        
        
        rep  = (a-b>0?a-b+1:b-a+1);
        stn = (n>m?m:n);
        for(int i=0;i<rep;i++){
            rst += stn + cnt;
            cnt++;
        }
        
    }
    else{//부호 다름

        if(a==b){
            rst = 0;
        }
        else{
            rep = (a-b>0?a-b:b-a);

            if(n>m){
            stn = (n>m?n:m);
            for(int i=0;i<rep;i++){
                rst += stn + cnt;
                cnt--;
            }
            }
            else{
            stn = (n<m?n:m);
            for(int i=0;i<rep;i++){
                rst += stn + cnt;
                cnt++;
            }
        }
        }
        
        
    }
    printf("%d",rst);
}
/*
경우의 수
1> n>m
- n>m>0 (ex) 5 3 | 3 4 5 | 3번 반복 | 부호 같음 A | 작은 거부터 큰 숫자 순으로 1증가
- n>0,m<0 (ex) 5 -3 |4 5 | 2번 반복 | 부호 다름 B | 큰 수 부터 작은 수 순으로-1 감소
               5 -10 | -6 -7 -8 -9 -10 | 5번 반복 | 부호 다름 | 작은 거 부터 +1 증가
- 0>n>m (ex) -2 -4 | -2 -3 -4 | 3번 반복 | 부호 같음 A | 작은 수부터 큰 숫자 순으로 1증가
- |n| = |m| (ex) 1000 -1000 | 0 | 1번 | 부호 다름 B

2> n<m
- m>n>0 (ex) 3 5 | 3 4 5 | 3번 반복 | 부호 같음 A | 작은 거부터 큰 숫자 순으로 1증가
- m>0,n<0 (ex) -7 9 | 8 9 | 2번 반복 | 부호 다름 | 큰 수부처 -1
- 0>m>n (ex)  -10 -7 | -10 -9 -8 -7 | 4번 반복 | 부호 같음
- |m| = |n| (ex) 1000 -1000 | 0 | 1번 | 부호 다름 B

3> n=m
- n=m>0 (ex) 2 2 | 2 | 부호 같음
- n=m<0 (ex) -2 -2 | -2 | 부호 같음


부호가 같은 경우


*/
// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
