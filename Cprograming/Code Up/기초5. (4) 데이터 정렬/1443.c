#include <stdio.h>
int a[10001];
int n, i, j, temp, key;
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);//n개의 숫자를 입력받음

    /*정렬된 데이터 셋에 뒤쪽에서 부터 원소를 하나씩 삽입하여 순서에 맞는 위치로 찾아가며 정렬하는 방식*/
    for (i=2; i<=n; i++)//2~5까지 반복
    {
        key=a[i];
// 이 부분에 들어가야 될 코드를 작성하여 제출
        for (j=i-1; j>=1 && key <= a[j]; j--)
            {////저장된 데이터가 확인한 데이터 보다 큰 경우
                a[j+1]=a[j];//뒤쪽으로 땡김 -> : 연결된 두개의 값 중 뒤의 값이 작은 경우
            }
        a[j+1]=key;
    }

    for (i=1; i<=n; i++)
        printf("%d\n", a[i]);
    return 0;
}