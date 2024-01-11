#include <stdio.h>
int a[10001];
int n, i, j, temp, min;
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++)//1~5까지 5번 반복
        scanf("%d", &a[i]);

    for (i=1; i<n; i++) {//4번 반복 1~4
        min=i;//최솟값에 1을 저장 (1,3,2,5,4)
        for (j=i+1; j<=n; j++) {// 2~5 / 3~5 / 4~5 / 5~5
// 이 부분에 들어가야 될 코드를 작성하여 제출: 선택 정렬
            if(a[min] > a[j]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for (i=1; i<=n; i++)
        printf("%d\n", a[i]);
    return 0;
}