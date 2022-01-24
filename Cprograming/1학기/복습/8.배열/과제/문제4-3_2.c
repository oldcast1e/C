#include  <stdio.h>
int main(){
    
    int n,min,max;
    int maxcnt,mincnt;
    int key = 1;
    int num[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=n-1;i>=0;i--){
        printf("%d ",num[i]);
    }
    printf("\n");
    while (key==1)
    {
        if(key == 0) break;

        maxcnt = 0,mincnt=0;
        for(int i=0;i<n;i+=3){
            min = num[i];
            max = num[i];
            if(i<=15){
                
                for(int j=i;j<i+3;j++){
                    if(num[i]!=-1){
                        if(num[j]>max){
                                max = num[j];
                                maxcnt ++;
                            } 
                        if(num[j]<min){
                            min= num[j];
                            mincnt ++;
                        }
                    } 
                }
            }
            else{
                max = (num[i]>num[i+1]?num[i]:num[i+1]);
                min = (num[i]<num[i+1]?num[i]:num[i+1]);
            }
            num[i/3] = max;
            num[(n-1)-i/3] = min;
        }
        if(maxcnt<=1 && mincnt<=1) key = 0;
        for(int i=0;i<maxcnt;i++){
            printf("<maxcnt>:%d",maxcnt);
            printf(" %d",num[i]);
        }
        printf("\n");
        for(int i=19;i>19-mincnt;i--){
            printf("<mincnt>:%d",mincnt);
            printf(" %d",num[i]);
        }
        
    }
    



}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
