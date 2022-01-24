#include  <stdio.h>
int main(){
    
    int N,cnt,key,spn=0;
    int num[50],rst[50];
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }

    for(int i=0;i<N;i++){
        cnt = 0;
        for(int j=0;j<N;j++){
            if(num[i]==num[j])
                cnt ++;
        }
        rst[i] = cnt;
    }
    

    for(int i=0;i<N;i++){
        if(i==0){
            printf("%d %d\n",num[i],rst[i]);
        }
        else{
            key = 1;
        for(int j=0;j<i;j++){
            if(num[i]==num[j])
                key = 0;
        }
        if(key==1){
            if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
                printf("\n");
            spn++;//줄 띄움 변수 증가
            printf("%d %d",num[i],rst[i]);
        }
        }
        
    }
    
    



}



