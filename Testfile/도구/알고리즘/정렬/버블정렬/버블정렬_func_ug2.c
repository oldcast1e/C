#include <stdio.h>
#include<stdlib.h>

#define swap(type, x,y)do{type t = x; x = y; y=t;}while(0)

void bubble(int a[], int n){
    int k= 1;
    while(k < n){
        int last = n;
        for(int j=1; j<=k; j++){
            // printf(">[%d][%d]\n",k,j);
            if (a[j] > a[j+1]){swap(int,a[j],a[j+1]);}
            last = last - j;
        }
        k = last;
    }
}
int main() {
    int n, temp;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int)*n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    bubble(a,n);
    for (int i = 1; i <= n; i++) printf("%d\n", a[i]);
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