#include <stdio.h>
#include <stdlib.h>

// 정점 개수 상수 정의 (고정된 6개의 정점)
#define MAX_VERTICES 6

// 인접 리스트의 노드 구조체 정의
typedef struct Node {
    int vertex;               // 인접 정점 번호
    int weight;               // 간선의 가중치
    struct Node* next;        // 다음 인접 노드 포인터
} Node;

// 그래프 구조체 정의 (인접 리스트 방식)
typedef struct Graph {
    Node* adjList[MAX_VERTICES]; // 각 정점의 인접 리스트
} Graph;

// 그래프 초기화 함수
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjList[i] = NULL; // 모든 인접 리스트를 NULL로 초기화
    }
    return graph;
}

// 새로운 노드 생성 함수
Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 간선 추가 함수 (무방향 간선)
void addEdge(Graph* graph, int src, int dest, int weight) {
    // src -> dest 간선 추가
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // dest -> src 간선 추가 (무방향 그래프이므로 양쪽에 간선을 추가)
    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// 초기 그래프 설정 함수 (수정된 간선 및 가중치로 설정)
void initializeGraph(Graph* graph) {
    addEdge(graph, 0, 1, 1); // 정점 1과 2: 가중치 1
    addEdge(graph, 0, 2, 1); // 정점 1과 3: 가중치 1
    addEdge(graph, 0, 3, 1); // 정점 1과 4: 가중치 1
    addEdge(graph, 0, 5, 2); // 정점 1과 6: 가중치 2
    addEdge(graph, 1, 2, 1); // 정점 2와 3을 가중치 1로 연결
    addEdge(graph, 5, 4, 3); // 정점 6과 5: 가중치 3
    addEdge(graph, 4, 4, 4); // 정점 5과 5: 가중치 4 (루프)
    addEdge(graph, 2, 4, 4); // 정점 3과 5: 가중치 4
}

// 간선 삭제 함수 (무방향 간선)
void removeEdge(Graph* graph, int src, int dest) {
    Node* temp = graph->adjList[src];
    Node* prev = NULL;

    // src -> dest 간선 삭제
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) { // 간선이 존재하면 삭제
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            graph->adjList[src] = temp->next;
        }
        free(temp);
    }

    // dest -> src 간선도 삭제
    temp = graph->adjList[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) { // 간선이 존재하면 삭제
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            graph->adjList[dest] = temp->next;
        }
        free(temp);
    }
}

// 간선 수정 및 추가 함수 (가중치가 0이면 삭제)
void modifyEdge(Graph* graph, int src, int dest, int weight) {
    Node* temp = graph->adjList[src];
    int found = 0;

    // src -> dest 찾기 및 가중치 수정
    while (temp != NULL) {
        if (temp->vertex == dest) {
            found = 1;
            if (weight == 0) {
                removeEdge(graph, src, dest); // 가중치가 0이면 삭제
            } else {
                temp->weight = weight;       // 가중치가 0이 아니면 수정
            }
            break;
        }
        temp = temp->next;
    }

    if (!found && weight != 0) {
        // 간선이 없고 가중치가 0이 아닌 경우 새 간선 추가
        addEdge(graph, src, dest, weight);
    }
}

// 인접 노드 출력 함수 (오름차순 정렬 후 출력)
void printAdjacent(Graph* graph, int vertex) {
    Node* head = graph->adjList[vertex];
    if (!head) {
        printf("-1\n"); // 해당 정점이 없으면 -1 출력
        return;
    }

    // 임시 배열을 이용해 정렬된 출력 준비
    Node* temp = head;
    Node* nodes[MAX_VERTICES];
    int count = 0;

    while (temp) {
        nodes[count++] = temp;
        temp = temp->next;
    }

    // 노드 번호를 기준으로 오름차순 정렬
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (nodes[i]->vertex > nodes[j]->vertex) {
                Node* tempNode = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = tempNode;
            }
        }
    }

    // 정렬된 결과 출력
    for (int i = 0; i < count; i++) {
        printf("%d %d ", nodes[i]->vertex + 1, nodes[i]->weight);
    }
    printf("\n");
}

// 메모리 해제 함수
void freeGraph(Graph* graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}

// 메인 함수
int main() {
    Graph* graph = createGraph();
    initializeGraph(graph); // 그래프 초기화 (그림 1과 동일한 구조)

    char command;
    int a, b, w;

    while (1) {
        scanf(" %c", &command); // 명령어 입력
        if (command == 'a') {
            scanf("%d", &a);
            if (a < 1 || a > MAX_VERTICES) {
                printf("-1\n");
                continue;
            }
            printAdjacent(graph, a - 1); // 인접 노드 출력
        } else if (command == 'm') {
            scanf("%d %d %d", &a, &b, &w);
            if (a < 1 || a > MAX_VERTICES || b < 1 || b > MAX_VERTICES) {
                printf("-1\n");
                continue;
            }
            modifyEdge(graph, a - 1, b - 1, w); // 간선 수정 또는 삭제
        } else if (command == 'q') {
            break; // 프로그램 종료
        }
    }

    freeGraph(graph); // 그래프 메모리 해제
    return 0;
}
