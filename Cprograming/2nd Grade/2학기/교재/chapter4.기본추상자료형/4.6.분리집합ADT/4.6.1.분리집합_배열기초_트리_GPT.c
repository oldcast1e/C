#include <stdio.h>

#define SIZE 12 // 전체 원소 수

int Parent[SIZE]; // 부모를 저장하는 배열
int Rank[SIZE];   // 각 노드의 트리 높이를 저장 (랭크)

// 초기화: 각 원소는 자기 자신을 부모로 가리키도록 설정
void makeSet() {
    for (int i = 0; i < SIZE; i++) {
        Parent[i] = i;
        Rank[i] = 0; // 처음에는 모든 트리의 높이가 0
    }
}

// 루트 노드 찾기 (경로 압축 적용)
int find(int x) {
    if (Parent[x] != x) {
        Parent[x] = find(Parent[x]); // 경로 압축
    }
    return Parent[x];
}

// 두 집합을 합치기 (랭크 기반 결합)
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (Rank[rootX] > Rank[rootY]) {
            Parent[rootY] = rootX; // rootX가 더 높으므로 rootY를 rootX에 연결
        } else if (Rank[rootX] < Rank[rootY]) {
            Parent[rootX] = rootY; // rootY가 더 높으므로 rootX를 rootY에 연결
        } else {
            Parent[rootY] = rootX; // 높이가 같으면 rootY를 rootX에 연결하고, rootX의 랭크를 증가
            Rank[rootX]++;
        }
    }
}

// 트리를 계층적으로 출력하는 함수 (DFS 기반)
void printTree(int node, int depth) {
    // 현재 노드를 출력 (들여쓰기 적용)
    for (int i = 0; i < depth; i++) {
        printf("  "); // 깊이만큼 들여쓰기
    }
    printf("%d\n", node);

    // 자식 노드를 재귀적으로 출력
    for (int i = 0; i < SIZE; i++) {
        if (Parent[i] == node && i != node) { // 부모가 현재 노드인 경우
            printTree(i, depth + 1); // 깊이를 증가시키면서 출력
        }
    }
}

// 각 집합을 트리 형태로 출력하는 함수
void printAllTrees() {
    int visited[SIZE] = {0}; // 방문 여부 체크

    printf("\n트리 상태:\n");
    for (int i = 0; i < SIZE; i++) {
        int root = find(i);
        if (!visited[root]) { // 루트 노드를 기준으로 트리 출력
            printf("집합 %d:\n", root);
            printTree(root, 0); // 루트에서부터 시작하는 트리 출력
            visited[root] = 1; // 루트 노드 방문 표시
        }
    }
}

int main() {
    // 집합 A = {1, 4, 7}, B = {2, 3, 6, 9}, C = {0, 5, 8, 10, 11}
    makeSet();

    // A 집합 결합
    unionSets(1, 4);
    unionSets(4, 7);

    // B 집합 결합
    unionSets(2, 3);
    unionSets(3, 6);
    unionSets(6, 9);

    // C 집합 결합
    unionSets(0, 5);
    unionSets(5, 8);
    unionSets(8, 10);
    unionSets(10, 11);

    // Parent 배열 출력 (배열 상태 확인)
    printf("Parent 배열 상태:\n");
    for (int i = 0; i < SIZE; i++) {
        // printf("%d -> %d\n", i, Parent[i]);
        printf("[%d] ", Parent[i]);
    }

    // 트리 상태 출력 (계층 구조로 표현)
    // printAllTrees();

    return 0;
}
