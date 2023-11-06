#include<stdio.h>

int main(){
    int num[50][2],n,cnt;
    char arr[50][20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s %d",arr[i],&num[i][0]);
    for(int i=0;i<n;i++){//비교주체
        cnt = 0;
        for(int j=0;j<n;j++){
            if(i!=j)if(num[j][0]>num[i][0])cnt++;
            num[i][1] = cnt;
        }
    }
    for(int i=0;i<n;i++)if(num[i][1]==2){printf("%s",arr[i]);break;}
} 
/*

*/