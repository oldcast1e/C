#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int input(int *p){
    int cnt = 0;
    for(int i=0;;i++){
        scanf("%d",(p+i));
        if(*(p+i)== -1){
            cnt = i;break;
        }
    }
    return cnt;

}
/*
배열 x의 시작 주소를 인자로 받아 종료 조건까지 정수를 입력받아 배열에 저장하고, 배
열 원소의 개수를 반환한다. 
*/

int *sel_next(int *p){//마지막 주소 반환

    int *rstdir;
    int sum = 0;

    for(int *i=p; ;i++){
        sum+= *i;
        if(sum<=10){
            rstdir = i;
            if(*i==-1) break;
        }
    }
    printf("%s","dddd");
    return rstdir;
}

int number(int *p, int *q){

    int sum = 0,*i;
    int rst = 0;
    for(i=p;i<=q;i++){
        sum += *i;
        if(sum<=10){
            rst += *i;
            rst *=10;
            if(*(i+1)==-1) break;
        }
    }
    return rst /=10;
}
/*
◦ x[M]의 위치와 sel_next에서 반환된 위치를 인자로 받아, 두 포인터 사이의 한 자리 정수
를 모아, 하나의 정수로 만들어 반환 한다. 

*/


int main(){

    int str[101],*pstr = str;
    int num = input(str),M;
    // printf("%d",num);
    
    int cnt = 0,sum = 0;
    int *stdir = str,*enddir;

    for(int i=0;i<num;i++)printf("%d ",*(pstr+i));

    for(int i=0;i<num;i++){

        enddir = sel_next(str);
        printf("><");
        // printf("%d*\n",number(str,str+5));
        //x[M]의 위치와 sel_next에서 반환된 위치를 인자로 받아
        
        stdir = sel_next(str);
        //*sel_next(int *p){//마지막 주소 반환
        
        cnt++;
    }

}
