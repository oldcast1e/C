#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
[하노이의탑, 하노이탑]
*/
int rst = 0,arr[100][2];
void hanoi(int n, int start, int end, int tmp){
    rst ++;
    if(n==1) {
        // printf("[%d]->[%d]\n",start,end);
        // printf("%d %d\n",start,end);
        arr[rst][0] = start;
        arr[rst][1] = end;
    }
    else{
        hanoi(n-1,start,tmp,end);
        // printf("[%d]->[%d]\n",start,end);
        // printf("%d %d\n",start,end);
        arr[rst][0] = start;
        arr[rst][1] = end;
        hanoi(n-1,tmp,end,start);
    }

}
int main(){#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rst = 0;
void hanoi(int n, int start, int end, int tmp){
    rst ++;
    if(n==1) printf("[%d]->[%d]\n",start,end);
    else{
        hanoi(n-1,start,tmp,end);
        printf("[%d]->[%d]\n",start,end);
        hanoi(n-1,tmp,end,start);
    }
}
int main(){
    int num; 
    printf("탑의 개수를 입력하세요: ");scanf("%d",&num); 
    hanoi(num,1,3,2);
    printf("재귀 횟수: %d",rst);
}
    int num; 
    //printf("탑의 개수를 입력하세요: ");
    scanf("%d",&num); 
    
    hanoi(num,1,3,2);
    // printf("재귀 횟수: %d",rst);
    printf("%d\n",rst);
    for(int i=0;i<rst;i++)printf("%d %d\n",arr[i][0],arr[i][1]);

    
} 
/*
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3
*/