#include  <stdio.h>
int main(){
    
    int N,tmp=0;
    scanf("%d",&N);
    int num[30];
    int max[30],min[30];
    for(int i=0;i<30;i++){
        max[i] = -1;
        min[i] = 21;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
        max[i] = num[i];
        min[i] = num[i];
    }
    for(int i=N-1;i>=0;i--){
        printf(" %d",num[i]);
    }

    int cnt = (N%3==0?N/3:(N/3)+1);
    while(1){

        for(int i=0;i<cnt;i++){
            for(int j=0;j<3;j++){
                if(max[tmp]>max[i]) max[i] = max[tmp];
                if(min[tmp]<min[i]) min[i] = min[tmp];

                tmp ++;
            }
        
        max[i+1] = -1,max[i+2]=-1;
        min[i+1] = 21,min[i+2]= 21;
        }
        // printf("\n");
        // for(int k=0;k<cnt;k++){
        //     printf(" %d",max[k]);
        // }
        printf("\n");
        for(int k=0;k<cnt;k++){
            printf(" %d",min[k]);
        }
        if(cnt==1) break;
        if(cnt%3==0) cnt/=3;
        else cnt = cnt/3+1;

        tmp = 0;
        
    }

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
