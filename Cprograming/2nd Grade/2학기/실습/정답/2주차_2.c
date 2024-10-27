#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;scanf("%d",&n);
    int *num = (int*)malloc(sizeof(num)*n+1);

    for(int i=0;i<n;i++){scanf("%d",&num[i]);}
    
    int nowdir,tmp,now;
    for(int i=0;i<n;i++){
        // max = num[0]; maxdir = 0;
        now = num[i]; nowdir = i;
        for(int j=0;j<i;j++){
            // if(max< num[j]){max = num[j]; maxdir = j;}
            // printf("now : %d | num[j] = %d\n",now,num[j]);
            if(now < num[j]){
                tmp = num[nowdir]; 
                num[nowdir] = num[j]; 
                num[j] = tmp;
            }
        }
        for(int i=0;i<n;i++){printf("%d ",num[i]);} printf("\n");

    }
    for(int i=0;i<n;i++){printf("%d ",num[i]);} //printf("\n");
    
}
/*




3 73 48 31 8 11 20
3 73 48 31 8 11 20
3 48 73 31 8 11 20
3 48 31 73 8 11 20
*/