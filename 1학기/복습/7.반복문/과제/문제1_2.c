#include  <stdio.h>//accept
int main(){
    int n,m,rep,stn,tmp;//덧셈 연산의 최적화
    int rst = 0,cnt=0;
    scanf("%d %d",&n,&m);
    if(n<m){//n>=m순으로 변경
        tmp = n;
        n= m;
        m = tmp;
    }
    int a = (n>0?n:n*-1);// n 의 절대값
    int b = (m>0?m:m*-1); //m의 절대값
    if(n*m>0){//부호 같은 경우
        rep = (a>b?a-b+1:b-a+1);
        for(int i=0;i<rep;i++){
            rst += n - cnt;
            cnt++;
        }
    }
    else{//부호가 다른 경우
        if(a==b)
            rst = 0;
        else{
            rep = (a>b?a-b:b-a);
            if(a>b){//큰 수부터 -1
                for(int i=0;i<rep;i++){
                    rst += n - cnt;
                    cnt++;
                }
            }
            else{//a<b
                for(int i=0;i<rep;i++){
                    rst += m + cnt;
                    cnt++;
                }
            }
        }
    }
    printf("%d",rst);
}


/*
경우의 수
--------------------
<1> n>m

(1) |n|>|m|
- n>m>0
(ex) 9 5 | 부호 같음 | 5 6 7 8 9 | 5번 | 큰 수 부터 -1
- n>0,m<0 
(ex) 9 -5 | 부호 다름 | 6 7 8 9 | 4번 | 큰 수부터 -1

(2) |n|<|m|
- n>0,m<0
(ex) 5 -9 | 부호 다름 | -6 -7 -8 -9| 4번 | 작은 수 부터 +1
- 0>n>m
(ex) -3 -9 | 부호 같음 | -3 -4 -5 -6 -7 -8 -9 | 7개| 큰 수 부터 -1

(3) |n|=|m|

- n>0,m<0
(ex) 7 -7 | 부호 다름
-----------------------
<2> n<m
(1) |n|>|m|

- m>0,n<0
(ex) -8 7 | 부호 다름
- 0>m>n
(ex) -8 -7 | 부호 같음 | -7 -8 | 2번 반복

(2) |n|<|m|
- m>n>0
(ex) 7 8 | 부호 같음 | 7 8 | 2번 반복
- m>0,n<0
(ex) 5 -4 | 부호 다름

(3) |n|=|m|

- m>0,n<0
(ex) -7 7 | 부호 다름
-------------------
<3> n=m
(ex) 8 8 | 부호 같음 | 0
(ex) -9 -9 | 부호 같음 | 0

*/