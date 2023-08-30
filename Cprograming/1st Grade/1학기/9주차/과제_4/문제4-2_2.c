#include  <stdio.h>
int main(){
    
    int N,rep,cnt,recnt=0;//cnt는 max,min의 순서값
    int M,m;

    int num[20];
    int max[20],min[20];
    for(int i=0;i<20;i++){//n-1번째 부터 0번째 배열 요소를 
        min[i]=21;
        max[i]=-1;//출력
    }



    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    for(int i=N-1;i>=0;i--){//n-1번째 부터 0번째 배열 요소를 
        printf(" %d",num[i]);//출력
    }

    if(N%3==1 || N%3==2) rep = N/3+1; //(ㄱ)
    else rep = N/3;//(ㄴ)

    if(N%3==1 || N%3==2){

        //최대값
        cnt = 0;
        for(int i=0;i<N-(N%3)+1;i+=3){//ex)5이면 1번반복(1,2,3)/8이면 2번(1,2,3/4,5,6)반복
            if(num[i]>num[i+1] && num[i]>num[i+2] ){
                max[cnt] = num[i];
                printf("<%d>",cnt);
                cnt++;
                
            } 
            else if(num[i+1]>num[i] && num[i+1]>num[i+2] ){
                max[cnt] = num[i+1];
                printf("<%d>",cnt);
                cnt++;
            } 
            else if(num[i+2]>num[i] && num[i+2]>num[i+1] ){
                max[cnt] = num[i+2];
                printf("<%d>",cnt);
                cnt++;
            } 
            
        }
        // M = num[N-(N%3)];//최댓값

        // for(int i=0;i<N%3;i++){//ex)4이면 1번반복(5)/8이면 2번(7,8)반복//ex)5이면 2번반복(4,5)/8이면 2번(7,8)반복
        //     if(num[N-(N%3)+i]>M){
        //         max[cnt] = num[N-(N%3)+i];
        //         printf("<%d>",cnt);
        //         cnt++;
        //     }
        // }

        
        /////////체크
        printf("\n");
        for(int i=0;i<cnt;i++){//n-1번째 부터 0번째 배열 요소를 
        printf(" %d",max[i]);//출력
        }
        //////////

        //최솟값
        cnt = 0;

        for(int i=0;i<N-(N%3)+1;i+=3){//ex)5이면 1번반복(1,2,3)/8이면 2번(1,2,3/4,5,6)반복
            if(num[i]<num[i+1] && num[i]<num[i+2] ){
                min[cnt] = num[i];
                printf("<%d>",cnt);
                cnt++;
                
            } 
            else if(num[i+1]<num[i] && num[i+1]<num[i+2] ){
                min[cnt] = num[i+1];
                printf("<%d>",cnt);
                cnt++;
            } 
            else if(num[i+2]<num[i] && num[i+2]<num[i+1] ){
                min[cnt] = num[i+2];
                printf("<%d>",cnt);
                cnt++;
            } 
            
        }
        // m = num[N-(N%3)];//최솟값

        // for(int i=0;i<N%3;i++){//ex)4이면 1번반복(5)/8이면 2번(7,8)반복//ex)5이면 2번반복(4,5)/8이면 2번(7,8)반복
        //     if(num[N-(N%3)+i]<=m){
        //         min[cnt] = num[N-(N%3)+i];
        //         printf("<%d>",cnt);
        //         cnt++;
        //     }
        // }
        printf("\n");
        for(int i=0;i<cnt;i++){//n-1번째 부터 0번째 배열 요소를 
        printf(" %d",min[i]);//출력
        }
        

    }
}
