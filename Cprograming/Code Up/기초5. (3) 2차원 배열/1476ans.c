#include <stdio.h>
int main()
{
    int Arr[101][101] = {};
    
    
    int n,m;
    scanf("%d %d", &n, &m);
    int val = 1;
    int j = 1;
    for(int i = 1; i <=n+m; i++){
        int temp_i = i;
        
        if(temp_i > n){
            temp_i = n;
            j++;
        }

        int temp_j = j;

        while(temp_i > 0){
            printf("i(%d) + 1 ==  temp_i(%d) + temp_j(%d)\n",i,temp_i ,temp_j );
            if(i + 1 ==  temp_i + temp_j){
                printf(">>\n>>조건 부합: i(%d) + 1 ==  temp_i(%d) + temp_j(%d)\n",i,temp_i ,temp_j );
                Arr[temp_i][temp_j] = val;
                val++;
                
            }
                temp_i--;
                temp_j++;
            
            if(temp_j > m){break;}
        }
        
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m ; j++){
    //         printf("%d ",Arr[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}
/*
*/
 