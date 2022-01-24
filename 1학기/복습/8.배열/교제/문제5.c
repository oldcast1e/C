#include  <stdio.h>
int main(){
    
    int N[100],cnt = 0,repcnt=1;
    int num,key = 1;
    int sum = 0;
    while(1){
        scanf("%d",&N[cnt]);
        num = N[cnt];
        if(cnt>0){
            for(int i=0;i<cnt;i++){
                if(num==N[i])
                    key =0;
            }
        }
        if(key == 0)
            break;
        sum += N[cnt];
        cnt++;  
    }
    printf("%d",sum);
}
// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
