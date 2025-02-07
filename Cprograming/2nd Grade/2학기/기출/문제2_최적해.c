/*
2. 10kg의 배낭에 최대의 총 이득을 주는 물건을 선택하는 프로그램을 작성하라. 최적해는 Dynamic
Programming 기법을, 탐욕해는 Greedy 기법을 이용한다.
*/

/*
문제를 분석한 결과, 이 문제는 **배낭 문제(Knapsack Problem)**의 변형입니다. 
10kg의 제한된 배낭 용량에서 각 물건의 무게와 이득을 고려하여 최대 총 이득을 얻도록 물건을 선택해야 합니다.

Dynamic Programming (DP) 접근법은 최적해를 보장합니다.
Greedy 접근법은 근사해를 구하지만 항상 최적해를 보장하지는 않습니다.
*/

#include <stdio.h>

// 물건 구조체 정의
typedef struct {
    char name;   // 물건 이름
    int weight;  // 물건 무게
    int value;   // 물건 가치
} Item;

#define MAX_WEIGHT 10
#define ITEM_COUNT 5

// DP 기반 배낭 문제 해결 함수
void knapsackDP(Item items[], int n, int maxWeight) {
    int dp[n + 1][maxWeight + 1];
    int i, w;

    // DP 테이블 초기화
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // 초기값 설정
            } else if (items[i - 1].weight <= w) {
                // 선택하는 경우와 선택하지 않는 경우 중 최대값
                dp[i][w] = (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w])
                               ? items[i - 1].value + dp[i - 1][w - items[i - 1].weight]
                               : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w]; // 선택하지 않는 경우
            }
        }
    }

    // 최적해 추적
    printf("Optimal Solution:\n");
    int totalValue = dp[n][maxWeight];
    printf("Total Value: %d\n", totalValue);

    printf("Selected Items: ");
    w = maxWeight;
    for (i = n; i > 0 && totalValue > 0; i--) {
        if (totalValue != dp[i - 1][w]) {
            printf("%c ", items[i - 1].name);
            totalValue -= items[i - 1].value;
            w -= items[i - 1].weight;
        }
    }
    printf("\n");
}

int main() {
    Item items[ITEM_COUNT] = {
        {'A', 8, 32}, {'B', 3, 15}, {'C', 9, 27}, {'D', 5, 5}, {'E', 2, 4}};

    knapsackDP(items, ITEM_COUNT, MAX_WEIGHT);

    return 0;
}
/*
P 테이블 dp[i][w]는 첫 번째 i개의 아이템 중에서 최대 w 무게를 사용해 얻을 수 있는 최대 가치를 저장합니다.
물건을 선택하거나 선택하지 않는 경우 중 최대 값을 취해 최적해를 계산합니다.
최종적으로 선택된 아이템을 추적하여 출력합니다.
*/