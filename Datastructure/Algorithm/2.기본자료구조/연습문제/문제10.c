#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
#define swap(tmp, x,y)do{tmp = x; x = y; y=tmp;}while(0)
//배열 a의 모든 요소의 순서를 뒤섞는 suffle함수를 작성하라

void suffle(int a[],int n){
    int fir,end,tmp;
    srand(time(NULL));
    for(int i=0;i<100;i++){
        do{fir  = rand()%90;}while(0>fir || fir > n);
        do{end  = rand()%90;}while(0>end || end > n);

        swap(tmp,a[fir],a[end]);
    }
    //update
}

int main(){
    int a[1000],cnt = 0;
    while(1){
        scanf("%d",&a[cnt]);
        if(a[cnt] < 0 ) break;
        cnt ++;
    }
    suffle(a,(cnt-1));
    for(int i=0;i<cnt;i++)printf("%d ",a[i]);

//12 34 123 87 9 54 23 97 53 -1

// /123 2 53 54 9 87 23 97 34 
}