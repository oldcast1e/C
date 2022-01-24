#include  <stdio.h>
int main(){
    
    int n,min,max,key=1,cnt=0;
    int num[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=n-1;i>=0;i--){
        printf("%d ",num[i]);
    }//반대로 출력
    printf("\n");

    while(key==1){
        for(int i=0;i<n;i+=3){
            
            if(cnt==0){
                min = num[i];
                max = num[i];
                if(i<=15){
                    if(num[i]!=-1){
                        for(int j=i;j<i+3;j++){//3개씩 비교하여
                        if(num[j]>max) max = num[j];
                        if(num[j]<min) min = num[j];
                    }
                    }
                }
                else{//나누는 이유는 i가 15이상인 경우 = 18일때 가능한 범위는 18~19이므로 3개 묶음 불가능
                    if(num[19]>max) max = num[19];
                    if(num[19]<min) min = num[19];
                }


            }
            else{
          
            }
            
            //배열이 [ㅁ,ㅁ,ㅁ]으로 되있다면
            num[i] = max;
            num[i+1] = min;
            if(i<=15) num[i+2] = -1;//[max,min,-1]형식으로 바꿈

            if(i<3){
                num[i/3] = max;
                num[i/3+1] = min;
            }
            else{
                num[i/3+1] = max;
                num[i/3+2] = min;
            }
            cnt++;
        }
        for(int i=0;i<n;i+=2){
            printf(" %d",num[i]);
        }
        printf("\n");

        for(int i=1;i<n;i++){
            printf(" %d",num[i]);//min만 저장되있는 인덱스만 출력
        }
    }
}

