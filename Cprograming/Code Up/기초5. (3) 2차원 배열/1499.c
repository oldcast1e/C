#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int a,int b){
    return(a>b?b:a);
}
int main(){
    int n,g,rst,cnt=0;
    int num[1000]={0};
    scanf("%d %d",&n,&g);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    if(n%g==0 ){
        for(int k=0;k<n/g;k++){
            cnt = -1002;
            for(int j=0;j<g;j++){
                if(num[k*g+j]==0){ num[k*g+j] = -1001;}
                if(num[k*g+j]>cnt)cnt = num[k*g+j];
            }
            printf("%d ",cnt);
        }
    }
    else{
        for(int k=0;k<n/g+1;k++){
            //1~ 5/3+1=2 = 1~2
            cnt = -1002;
            for(int j=0;j<g;j++){//0~2
                if(num[k*g+j]==0){ num[k*g+j] = -1001;}
                if(num[k*g+j]>cnt) cnt = num[k*g+j];
            }
            printf("%d ",cnt);
        }
    }
    // for(int k=1;k<=n/g;k++){//5->0
    //     // for(int j=0;j<g;j++){
    //     //     num[2*k], num[2*k+1]
    //     // }
    //     // num[k] = min(num[2*k], num[2*k+1]);
    //     printf("%d ",num[k]);
    //     //m[k] = min(m[2*k], m[2*k+1]); //k >= 0
    // }
  
    

    
} 
/*
5 3
1 3 5 4 2

6 3
1 3 5 4 2 7
*/