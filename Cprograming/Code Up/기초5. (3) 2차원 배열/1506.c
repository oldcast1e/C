#include<stdio.h>
int main(){

    int n,val = 1;
    int dnum[101][101];
    scanf("%d",&n);
    
    int row_max = n,row_min = 0,cro_max=n,cro_min=0;
    while(1){

    
        //printf("-------------\n");
        for(int i=row_min;i<row_max;i++){
            dnum[i][cro_min] = val;
            // printf("|| dnum[%d][%d] = %d\n",i,cro_min,val);
            val ++; 
        }cro_min ++; row_max --;
        if(val >= (n*n) ) break;
         //printf("----cro_min = %d | cro_max = %d----\n",cro_min,cro_max);
        
        for(int i=cro_min;i<cro_max;i++){
            dnum[row_max][i] = val;
            //printf(">>dnum[%d][%d] = %d\n",row_max,i,val);
            val ++;
        } row_max --; cro_max --;
        
        //printf("-------------\n");
        
        for(int i=row_max;i>=row_min;i--){
            dnum[i][cro_max] = val;
            //printf("|| dnum[%d][%d] = %d\n",i,cro_max,val);
            val ++; 
        }cro_max --;
        if(val >= (n*n) ) break;
        //printf("-------------\n");

        for(int i=cro_max;i>=cro_min;i--){
            dnum[row_min][i] = val;
            //printf("<<dnum[%d][%d] = %d\n",row_min,i,val);
            val ++; 
        }cro_min ++; row_min ++;
        // if(val >= (n*n) ) break;
        
        
        
        //printf("----row_min = %d | row_max = %d----\n",row_min,row_max);
        //printf("----cro_min = %d | cro_max = %d----\n",cro_min,cro_max);
        //printf("----n = %d | val = %d----\n",n,val);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) printf("%d ",dnum[i][j]);
        //     printf("\n");
        // } 
        
        cro_min -=1;
        row_max +=1;
        cro_max +=1;
        

    }
    // printf("결과\n");
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("%d ",dnum[i][j]);
            printf("\n");
        } 


}