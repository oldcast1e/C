#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,k,cnt,pre; 
    scanf("%d %d",&a,&k); cnt = k%2==0?2:1; pre = cnt;
    for(int i=0;i<a;i++){
        if(i==0 || i== (a-1)){for(int j=0;j<a;j++)printf("*");printf("\n");}
        else {
            printf("*"); cnt = pre;
            for(int j=1;j<a-1;j++){ //printf("초기 cnt값: %d\n",cnt);
                if((j==cnt || k==1) && a>k){
                    printf("*");
                    if((cnt+k) < a)cnt+=k;
                    // else cnt --;
                }
                else printf(" ");
            }
            // printf("*  >>cnt = %d | pre = %d\n",cnt,pre); 
            printf("*\n");
            if((pre-1) <= 0 ) pre = k;
            else pre --;
            // cnt = k%2==0?1:2;
            // printf("*\n");
            // if(cnt==1) cnt= k;
            // else cnt--;

        }
    }
 
} 
/*

*/
