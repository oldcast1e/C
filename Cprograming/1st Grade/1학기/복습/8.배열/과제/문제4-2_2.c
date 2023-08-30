#include  <stdio.h>
int main(){
    
    int n,min,max;
    int num[20]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(int i=n-1;i>=0;i--){
        printf("%d ",num[i]);
    }
    printf("\n");
    for(int i=0;i<n;i+=3){
        min = num[i];
        max = num[i];
        if(i<=15){
            for(int j=i;j<i+3;j++){
            if(num[j]!=-1){
                if(num[j]>max) max = num[j];
                if(num[j]<min) min = num[j];
            }
        }
        }
        else{
            if(num[19]>max) max = num[19];
            if(num[19]<min) min = num[19];
        }
        num[i] = max;
        num[i+1] = min;
        if(i<=15) num[i+2] = -1;
    }

    // for(int i=0;i<n;i++){
    //     printf("%d ",num[i]);
    // }
    for(int i=0;i<n;i+=3){
        printf(" %d",num[i]);
    }
    printf("\n");
    for(int i=0;i<n;i+=3){
        printf(" %d",num[i+1]);
    }
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
