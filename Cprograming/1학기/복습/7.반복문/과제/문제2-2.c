#include  <stdio.h>
int main(){
    
    int n,m,k,r,key = 0;
    int alicnt,alisum,alinum;
    int pf,maxalisum=-1,cnt,maxcnt,maxalicnt;
    //pf: 약수(2부터 시작)
    //alinum: 약수의 개수가 가장 큰 수
    //maxalisum: 약수의 개수가 가장 큰 수의 약수의 개수
    //maxcnt: 약수의 개수가 가장 큰 수의 소인수 지수의 합
    scanf("%d %d",&n,&m);
    while(m>=n){
        k = n;
        r = n;

        pf = 2;
        alisum = 1;
        alicnt = 0;
        cnt = 0;

        while(r>0){
            if(r%pf==0){
                cnt++;
                r/=pf;
                // printf("<%d> ",cnt);
            }
            else{
                pf++;
                alicnt += cnt;
                alisum *= (cnt+1);
                cnt = 0; 
                if(r<=1){
                    break;
                }
            }
        }
 
        if(alisum>maxalisum){
            maxalisum = alisum;
            alinum = k;
            maxalicnt = alicnt;
        }
        n++;
    }

    printf("%d %d %d",alinum,maxalisum,maxalicnt);
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
