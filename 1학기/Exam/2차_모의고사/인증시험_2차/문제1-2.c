#include  <stdio.h>
int main(){
    
    char u;
    int N,M,K,L;
    int cnt = 0,key,max;

    int num;
    int book[100]={0,};//방번호
    int rst[100]={0,};//방 번호 중복확인 배열
    scanf("%d %d",&N,&M);//<방번호>15 <인원>10

    while(1){
        getchar();
        scanf("%c",&u);//y
        key = 1;
        if(u=='y'){
            scanf("%d %d",&K,&L);//<방번호>12 <인원>9
            if(K>N || L>M){
                printf("please input correctly\n");
            }
            else{
                if(cnt==0){
                    rst[cnt] = K;
                    book[K] = L;
                    for(int j=0;j<N;j++){
                        printf("%d ",book[j]);
                    }
                    
                }
                else{
                    cnt ++;
                    for(int i=0;i<cnt;i++){
                        if(K==rst[i]) key = 0;
                    }

                    if(key==1){
                        for(int j=0;j<N;j++){
                            printf("%d ",book[j]);
                        }
                    }
                    else{
                        printf("please select another room");
                    }
                }
                

            }
            // for(int i=0;i<N;i++){
            //     printf("%d ",book[N]);
            // }
            // printf("\n");
        }
        else{
            
            while(cnt>0){
                num = 0;
                max = -1;
                for(int i=0;i<N;i++){
                    if(book[i]>max){
                        max = book[i];
                        num = i;
                    }
                }
                printf("%d %d",max,num+1);
                book[num] -=1;
                cnt --;

            }
        }
    }
    
}


