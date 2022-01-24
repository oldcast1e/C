#include  <stdio.h>
int main(){
    
    int twin[2][9];
    int cnt,key = 0;
    for(int i=0;i<2;i++){
        if(i==0){
            for(int j=0;j<9;j++){
                scanf("%d",&twin[i][j]);
            }
        }
        else{
            for(int j=0;j<4;j++){
                scanf("%d",&twin[i][j]);
            }
        }
    }
    for(int i=0;i<2;i++){
        if(i==0){

            cnt = 0;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    printf(" %d",twin[0][cnt]);
                    cnt ++;
                }
                printf("\n");   
            }
        }
        else{
            cnt = 0;
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    printf(" %d",twin[1][cnt]);
                    cnt ++;
                }
                printf("\n");
            }
        }
    }
    int x=-1,y=-1;
    for(int i=0;i<9;i+=3){//3번(0,3,6)
        for(int j=i;j<i+3;j++){//0~2 3~5 6~8 // 0 ->0 1->0
            if(twin[0][j]== twin[1][0] && twin[0][j+1]== twin[1][1]){
                if(twin[0][j+3]== twin[1][1] && twin[0][j+4]== twin[1][2]){
                    if(key ==0){
                        x =  (j==0 || j==3 || j==6?0:((j==1 || j==4 || j==7)?1:(j==2 || j==5 || j==8)?2:-1));
                        y = i/3;

                        key ++;
                        //printf("j = %d",j);
                    }
                    
                }
                    
            }
        }
    }
    
    if(x == -1 && y ==-1) printf("none");
    else{
        printf("\n");
        printf("%d %d",y,x);
    } 


}

//if(spn!=0) printf("\n");
//spn ++;

//3 3 3  1 1 3  1 1 3
/*
3 3 3
1 1 3
1 1 3
*/
//1 1 1 1