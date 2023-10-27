#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//소인수 분해를 하자!
int main(){
    int ipt,val,cnt=2,num=-1,key=1,rep=0;
    int fir,fir_cnt=0;
    float n1,n2;
    
    scanf("%d",&ipt); val = ipt;
    while (val>0){
        if(val <= 1)break;
        
        if(val%cnt == 0){
            if(fir_cnt ==0 ){fir = cnt;fir_cnt++;}; //24번째 줄에서 소수의 곱을 표현하기 위해 가장 먼저 나온 소수를 저장
            // printf("[%d] ",cnt);//1을 제외한 소인수 출력
            rep++;//1과 자기 자신을 제외한 소인수의 개수 저장
            if(num == cnt){printf("wrong number");key=0;break;}//똑같은 소인수가 나오면 종료
            num = cnt;
            val= val/cnt;
        }
        else cnt++;
    } 
    if(rep==2 && key == 1)printf("%d %d",fir,ipt/fir);
    else if(key==1)printf("wrong number");
    
    
 
} 

/*
두 소수의 곱을 암호로 사용하는 알고리즘은 큰 수의 소인수분해가 어렵기 때문에 안전하다고 알려져있다.

그렇지만, 만약 두 소수를 잊어버리면 어떻게 될까? 굉장히 난감할 것이다.

이에 대비해 어떤 수(n)가 입력되면 두 소수의 곱으로 나타낼 수 있으면 두 소수를 오름차순으로 출력하고,

그렇지 않으면 "wrong number"를 출력하는 프로그램을 작성하시오.
*/