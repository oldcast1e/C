#include  <stdio.h>
int main(){
    
    char u[100], x[100],y[100];

    int  cnt=0,cnt1= 0,cnt2=0;
    int rst1=0,rst2=0,key=1;
    while (1)
    {
        scanf("%c",&u[cnt]);

        if(u[cnt]=='*'){
            if(key==1){
                for(int i=0;i<cnt;i++){
                    x[i] = u[i];
                }
                cnt1 = cnt;
                cnt = -1;
                key = 2;
                for(int i=0;i<100;i++){
                    u[i] = 0;
                }
            }
            else if(key==2){
                for(int i=0;i<cnt;i++){
                    y[i] = u[i];
                }
                cnt2 = cnt;
                cnt = -1;
                break;
            }
        cnt++;
    }
    }
    for(int i=0;i<cnt1;i++){
        rst1 += x[i];
    }
    for(int i=0;i<cnt2;i++){
        rst2 += y[i];
    }

    if(rst1 == rst2 || rst1<rst2){
        for(int i=0;i<cnt1;i++){
            printf("%c",x[i]);
        }
    }
    else{
        for(int i=0;i<cnt2;i++){
            printf("%c",y[i]);
        }
    }
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가

