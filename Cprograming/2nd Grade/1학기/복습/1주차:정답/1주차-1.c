#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*정답*/

typedef struct node {
	int data;
	struct node* next;
}ListNode;

int sum(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cnt += j;
    }
    return cnt;
}

int main(){
 
    int n; scanf("%d",&n);
    printf("%d",sum(n));

} 
