#include <stdio.h>
int a[10001];
int n, i, j, temp;

void ABC(int a[],int n){
    n= 10;
    for(i=1; i<n; i++){
// 이 부분에 들어가야 될 코드를 작성하여 제출: 버블 정렬
        for(j=1; j<=n-i; j++)
        {
            if (a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (i = 1; i <= n; i++)printf(" %d", a[i]);
}

int main() {

    for (i=1; i<=10; i++)scanf("%d", &a[i]);
    ABC(a,n);

    
    return 0;
}
/*
5
1
3
2
5
4

*/