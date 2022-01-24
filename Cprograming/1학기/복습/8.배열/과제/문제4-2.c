#include  <stdio.h>
int main(){
    
    int N,max,key = 1,cnt=0;
    int num[20]={-1,};
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    for(int i=N-1;i>=0;i--){
        printf("%d ",num[i]);
    }
    printf("\n");
    while(key==1){
        for(int i=0;i<N;i+=3){
            if(num[i]>num[i+1] && num[i]>num[i+2]){
                num[i+1] = 0;
                num[i+2] = 0;
                num[cnt] = num[i];
                printf("%d ",num[i]);
                num[i] = 0;

            } 
            else if(num[i+1]>num[i] && num[i+1]>num[i+2]){
                num[i] = 0;
                num[i+2] = 0;
                num[cnt] = num[i+1];
                printf("%d ",num[i+1]);
                num[i+1] = 0;

            } 
            else if(num[i+2]>num[i+1] && num[i+2]>num[i]){
                num[i] = 0;
                num[i+2] = 0;
                num[cnt] = num[i+1];
                printf("%d ",num[i+1]);
                num[i+1] = 0;

            } 
            cnt++;

        }
        printf("\n");
        
    }
    
    

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
