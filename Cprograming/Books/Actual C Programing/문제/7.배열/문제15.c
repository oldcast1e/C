#include  <stdio.h>
int main(){
    
    int arr[20][20];
    int x=0,y = -1;
    int dir =1;//u

    int num = 1;
    int N,M,tmp;
    scanf("%d %d",&N,&M);//(j)
    tmp = N;
    N = M;
    M = tmp;

    int cnt1 = N,cnt2=M;

    while (N>=0){
    
        for(int i=0;i<N;i++){

            y = y+ dir;
            arr[x][y] = num;
            num++;
        }//

        N--;

        for(int i=0;i<M-1;i++){

            x = x + dir;
            arr[x][y]=num;
            num++;
        }
        
        M--;
        dir *=-1;
    }

    for(int i=0;i<cnt2;i++){

        for(int j=0;j<cnt1;j++){
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }


}
     

     

