#include  <stdio.h>

void selfnumber(){

    int num=1,swifnum;
    int cnt = 0,rst;
    int testnum = 1;

    int selfnumber[10000] = {0};
    for(int i=1;i<=10000;i++){
        selfnumber[i] = i;
    }

    while(1){
        
        if(cnt ==0){//cnt가 0일때
            rst = 0;
            cnt = 1;
            // if(num/10 != 0)
            rst += num;
            swifnum = num;
        }
        else{//cnt가 1일때
            rst += num%10;
            num /= 10;
        }

        if(num==0){
            cnt = 0;
            if(rst>10000) break;

            for(int i=1;i<=10000;i++){
                if(selfnumber[i]==rst) selfnumber[i] = 0;
            }
            // printf("%d\n",rst);
            num = swifnum;
            num ++;
        }

    }
    for(int i=1;i<=10000;i++){
        if(selfnumber[i]!=0)printf("%d\n",selfnumber[i]);
    }
}



int main(){

    selfnumber();
    

}




// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

