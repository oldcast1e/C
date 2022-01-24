#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int MAX(int *ar);
int MIN(int *ar);


int main(){
    int N,cnt,min,max,key;
    int ar[100],*par = ar;

    int point;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cnt = 0;
        while(1){
            scanf("%d",(par+cnt));
            if(*(par+cnt)==0) break;
            cnt ++;
        }
        max = MAX(ar);
        min = MIN(ar);
        

        key  = -1;
        point = 0;
        for(int j=0;j<cnt;j++){
            
            if(*(ar+j)== max && point != 2){ 
                point  = 1;
                key *= -1;
                j++;//최대값은 출력안함
            } //최댓값이 먼저 나옴
            else if(*(ar+j)== min && point != 1){ 
                point  = 2;
                j++;//최솟값은 출력안함
                key *= -1;
            } //최솟값이 먼저 나옴




            if(point == 1){//최댓값이 먼저 나옴
                if(*(ar+j+1)== min){
                    printf("%d ",*(ar+j));
                    key *= -1;//해당요소의 다음요소가 최소이면

                } 
            }
            else if(point == 2){//최솟값이 먼저 나옴
                if(*(ar+j+1)== max) {
                    printf("%d ",*(ar+j));
                    key *= -1;
                }//해당요소의 다음요소가 최대이면
            }

            if(key == 1) printf("%d ",*(ar+j));
            
        }
        printf("\n");


    }

}

int MAX(int *ar){
    int cnt = 0;
    int max  = *(ar+0);

    for(int i=1; ; i++){
        if(*(ar+cnt)==0) break;
        if(*(ar+cnt)>max){
            max = *(ar+cnt);
        }
        cnt++;
    }   
    return max;

}

int MIN(int *ar){

    int cnt = 0;
    int min  = *(ar+0);
    
    for(int i=1; ; i++){
        if(*(ar+cnt)==0) break;

        if(*(ar+cnt) < min){
            min = *(ar+cnt);
        }
        cnt++;
    }   
    return min;
    
}

/*
3 
3 7 6 5 5 -2 0
1 7 6 2 3 13 2 0 
2 0

2
13 7 6 6 2 0
7 3 4 5 6 7 10 4 0

*/

