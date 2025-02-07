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


/*탐욕기법*/
#include <stdio.h>

// 물건 구조체 정의
typedef struct {
    char name;   // 물건 이름
    int weight;  // 물건 무게
    int value;   // 물건 가치
    double ratio; // 가치 대비 무게 비율
} Item;

#define MAX_WEIGHT 10
#define ITEM_COUNT 5

// 물건 정렬 함수 (가치 대비 무게 비율 기준 내림차순)
void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// 탐욕 기법 기반 배낭 문제 해결 함수
void knapsackGreedy(Item items[], int n, int maxWeight) {
    sortItems(items, n); // 정렬

    int totalValue = 0, currentWeight = 0;
    printf("Greedy Solution:\n");
    printf("Selected Items: ");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= maxWeight) {
            printf("%c ", items[i].name);
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        }
    }

    printf("\nTotal Value: %d\n", totalValue);
}

int main() {
    Item items[ITEM_COUNT] = {
        {'A', 8, 32, 4.0}, {'B', 3, 15, 5.0}, {'C', 9, 27, 3.0}, {'D', 5, 5, 1.0}, {'E', 2, 4, 2.0}};

    knapsackGreedy(items, ITEM_COUNT, MAX_WEIGHT);

    return 0;
}

/*
물건을 "가치 대비 무게 비율" 기준으로 내림차순 정렬합니다.
무게 제한을 초과하지 않는 범위에서 순차적으로 물건을 선택합니다.
이 방식은 항상 최적해를 보장하지는 않지만, 간단한 구현으로 근사해를 빠르게 구할 수 있습니다.
*/