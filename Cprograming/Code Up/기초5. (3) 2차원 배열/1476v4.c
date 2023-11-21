#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,i,j=1,val=1;
    int Arr[101][101] = {};

    scanf("%d %d", &n, &m);
    for(i = 1;i< n+m;i++){
        int temp_i = i;

        if(temp_i > n){
            temp_i  = n;
            j++;
        }

        int temp_j = j;
        // printf("\n-------------- i = %d / temp_i = %d --------------\n",i,temp_i);
        while(temp_i > 0){
            Arr[temp_i][temp_j] = val;
            // printf("Arr[%d][%d] = %d\n",temp_i,temp_j,val);
            val ++;

            temp_i--;
            temp_j++;

            if(temp_j > m){break;}
        }
    }
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
     }
    

    
} 
/*

*/