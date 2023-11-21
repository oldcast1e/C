#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,i=1,j=1,val=1;
    int Arr[101][101] = {};

    scanf("%d %d", &n, &m);
    for(j = 1;j< n+m;j++){//

        int temp_j = m-j+1;
        if(temp_j <= 0){
            temp_j  = 1;
            i--;
        }
        printf("\n-------------- i = %d / j = %d / temp_j = %d --------------\n",i,j,temp_j);
        int temp_i = i;
        while(temp_j > 0){
            Arr[temp_i][temp_j] = val;
            printf("Arr[%d][%d] = %d\n",temp_i,temp_j,val);
            val ++;

            temp_j--;
            temp_i--;

            if(temp_j > m || temp_i < 1){break;}
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