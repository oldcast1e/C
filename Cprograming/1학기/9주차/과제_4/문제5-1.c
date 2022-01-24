#include  <stdio.h>
int main(){
    
    int num[100],n,cnt=0;
    int rst[100];
    int key=0;
    while(1){
        scanf("%d",&n);
        if(n<0)
            break;
        num[cnt] = n;
        cnt++;
    }

    // for(int k=0;k<cnt;k++){
    //     printf("%d",num[k]);
    // }


    for(int i=0;i<cnt+1;i++){
        if(i>=1){
            for(int j=0;j<i-1;j++){

            if(num[i]==num[j])
                key++;
        }
        if(key==0)
            rst[i] = 1;
        else
            rst[i] = 0;;
        }
    }

    for(int k=0;k<cnt;k++){
        printf("%d",rst[k]);
    }
}
