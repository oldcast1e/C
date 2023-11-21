#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0,val = 1;
    int dnum[100][100];
    
    scanf("%d %d",&a,&b);
    
    if(a <= b){
        int cnt_a=0;
        while(cnt_a < a){
            for(int i=0;i<=cnt_a;i++){
                dnum[cnt_a-i][i] = val;
                // printf("dnum[%d][%d] = %d\n",cnt_a-i,i,val);
                val++;
            }
            cnt_a++;
        }
        for(int i=1;i<=b-a-1;i++){//2
            for(int j=0;j<a;j++){
                dnum[cnt_a-1-j][i+j] = val;
                val++;
            }
        }
        int cnt_b = a-1,i=0;
        do
        {
            for(int j=0;j<a-i;j++){
                dnum[cnt_b-j][b-a+j+i] = val;
                printf(">>dnum[%d][%d] = %d\n",cnt_b-j,b-a+j+i,val);
                val++;
            }
            i++;
        } while (i<=cnt_b);
        
        // for(int i=0;i<cnt_b;i++){//4
        //     // if(cnt_b==0) break;;
        //     for(int j=0;j<a-i;j++){
        //         dnum[cnt_b-j][b-a+j+i] = val;
        //         printf(">>dnum[%d][%d] = %d\n",cnt_b-j,b-a+j+i,val);
        //         val++;
        //     }
        //     // cnt_b --;
        // }
    }

    if(a >b){
        // int cnt = a; a = b; b = cnt;
        int cnt_b=0;
        while(cnt_b < b){
            for(int i=0;i<=cnt_b;i++){
                dnum[cnt_b-i][i] = val;
                // printf("dnum[%d][%d] = %d\n",cnt_b-i,i,val);
                val++;
            }
            cnt_b++;
        }
        for(int i=0;i<a-b-1;i++){//2
            for(int j=0;j<b;j++){
                dnum[b-j+i][j] = val;
                // printf("==>dnum[%d][%d] = %d\n",b-j+i,j,val);
                val++;
            }
        }
        
        cnt_b = a-1;
        for(int i=0;i<cnt_b;i++){//4
            for(int j=0;j<b-i;j++){
                dnum[cnt_b-j][j+i] = val;
                // printf(">>dnum[%d][%d] = %d\n",cnt_b-j,j+i,val);
                val++;
            }
            // cnt_b --;
        }
       
    }
    // for(int i=0;i<a;i++)
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)printf("%d ",dnum[i][j]);
        printf("\n");
    }

    
} 
/*

*/