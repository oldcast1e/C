#include  <stdio.h>
int main(){
    
    char u[100], x[100],y[100];

    int  cnt=0,cnt1= 0,cnt2=0;
    int rst1=0,rst2=0;
    int key = 0;

    int k;

    int total = 0;

    while(1){

        if(key>1) break;
        scanf("%c",&u[cnt]);
        if(u[cnt]=='*'){
            if(key==0){
                cnt1 = cnt;
                for(int i=0;i<cnt1;i++){
                    x[i] = u[i];
                }
                key = 1;
            }
            else if(key ==1){
                cnt2 = cnt-cnt1-1;
                k = 0;
                for(int i=cnt1+1;i<cnt1+cnt2+1;i++){
                    y[k] = u[i];
                    k++;
                }
                key = 2;
            }
        }
        cnt++;
    }

    for(int i=0;i<cnt1;i++){
        rst1 += x[i]-97; 
    }
    for(int i=0;i<cnt2;i++){
        rst2 += y[i]-97; 
    }
    
    if(rst1<=rst2){
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

