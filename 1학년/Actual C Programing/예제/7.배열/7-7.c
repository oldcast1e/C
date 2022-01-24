#include  <stdio.h>
int main(){
    
    double A[4][4]={{0.0,0.1,0.2,0.3},
                    {1.0,1.1,1.2,1.3},
                    {2.0,2.1,2.2,2.3},
                    {3.0,3.1,3.2,3.3}};
    
    double B[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            B[i][j] = A[j][i];  
        }
    }
    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){
            printf("%.1lf ",A[i][j]);
        }
        printf("    ");

        for(int j=0;j<4;j++){
            printf("%.1lf ",B[i][j]);
        }
        printf("\n");

    }


    
}
