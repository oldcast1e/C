/*
다음의 문제 1과 문제 2는 주어진 그래프를 인접리스트 및 인접행렬로 각각 표현하여 해결해야
한다. 다음은 두 문제 모두에 공통된 사항이다.
1) 그림 1의 그래프에 관해 해결해야 한다.
2) 가중치의 값은 양수와 음수 모두 가능하나, 0은 허용하지 않는다.
3) 그림 1 그래프의 정점 개수는 변경되지 않는다. 단, 간선 개수는 변화할 수 있다. 참고로
정점 6개인 그래프에서 가능한 간선 개수는, 자기 자신으로 가는 간선(즉, 루프)을
포함하여 최대 21(= 6 + 5 + 4 + 3 + 2 + 1)개다.
4) 간선의 이름을 생략하기로 한다. 따라서 간선 구조체의 이름 필드는 정의하지 않아도
된다.
5) 그래프를 배열 또는 연결리스트 가운데 어느 것을 이용하여 구현할지는 각자의 판단에
맡긴다.

[ 문제 1 ] (인접리스트 구현) 그림 1의 무방향 가중그래프를 인접리스트로 표현하고, 다음
명령어에 따라 그래프 정보를 출력하거나 그래프를 수정하는 프로그램을 작성하시오.
대화식 프로그램에 주어지는 명령어는 a, m, q 세 가지며 각 명령에 대해 다음과 같이
수행해야 한다.
a <node number> : 
	<node number>를 가지는 node와 인접한 node와 그
	노드까지의 간선 가중치를 모두 인쇄. 단, node number의
	오름차순으로 인쇄하되, space 외의 구분자 없이 노드번호
	가중치 노드번호 가중치 ... 형식으로 인쇄한다. 그래프에 정점
	a가 존재하지 않으면 아무 것도 하지 않고 –1을 출력한다.
m a b w : 
	간선 (a, b)의 가중치를 w로 변경한다. 그러한 간선이 존재하지 않을 때는
	가중치 w인 새로운 간선 (a, b)를 생성한다. w = 0이면 간선 (a, b)를
	삭제한다. 그래프에 정점 a 혹은 b가 존재하지 않으면 아무 것도 하지
	않고 –1을 출력한다.
q : 프로그램 종료
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996) // 특정 경고 메시지를 비활성화 (4996번 경고)

typedef struct Graph {
	struct Vertex *vertex; // 정점 리스트
	struct Edge *edge;     // 간선 리스트
}Graph;

/*연결리스트*/
typedef struct Node {
	int edge_index;       // 간선의 인덱스
	struct Node *next;    // 연결 리스트의 다음 노드
}Node;

typedef struct Vertex {
	int id;               // 정점 ID
	struct Node *list;    // 간선 연결 리스트의 시작 노드
}Vertex;

typedef struct Edge {
	int from, to;         // 간선의 시작 정점과 끝 정점
	int weight;           // 간선 가중치
}Edge;


Node *create_node(int id) { // 입력받은 간선 인덱스를 가지는 노드 생성
	
	Node *newNode = (Node *)malloc(sizeof(Node)); 
	newNode->edge_index = id; // 간선 인덱스 
	newNode->next = NULL;     // 초기화 (다음 노드 없음)

	return newNode; // 생성된 노드 반환
}

// 정점을 초기화
void init_vertex(Vertex *vertex, int id) {
	vertex->list = create_node(-1); // 초기 연결 리스트 시작 노드 생성 (-1은 더미 노드)
	vertex->id = id;                // 정점 ID 설정
}

// 간선을 초기화
void init_edge(Edge *edge, int n) {
	int i, j, index = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) { // 가능한 모든 간선 조합 생성
			edge[index].from = i + 1;  // 시작 정점
			edge[index].to = j + 1;    // 끝 정점
			edge[index].weight = 0;    // 초기 가중치 설정
			index++;
		}
	}
}

// 간선의 가중치를 설정
void add_edge(Edge *edge, int index, int weight) {
	edge[index].weight = weight; // 간선 가중치 설정
}

// 간선 정보를 정점의 연결 리스트에 추가
void add_node(Vertex *vertex1, Vertex *vertex2, int edge_index) {
	Node *newNode = create_node(edge_index); // 새로운 노드 생성
	Node *tmp;

	tmp = vertex1->list; // vertex1의 연결 리스트 시작 노드
	if (tmp == NULL) 
		vertex1->list = newNode; // 리스트가 비어있다면 노드 추가
	else {
		while (tmp->next != NULL) { // 적절한 위치를 찾아 삽입
			if (tmp->next != NULL && tmp->next->edge_index > edge_index) break;
			tmp = tmp->next;
		}
		newNode->next = tmp->next; // 노드를 리스트에 삽입
		tmp->next = newNode;
	}

	if (vertex1 == vertex2) return; // 자기 자신과의 간선이면 한 번만 추가

	newNode = create_node(edge_index); // 다른 정점에 대한 노드 생성
	tmp = vertex2->list; // vertex2의 연결 리스트 시작 노드
	if (tmp == NULL) 
		vertex2->list = newNode; // 리스트가 비어있다면 노드 추가
	else {
		while (tmp->next != NULL) { // 적절한 위치를 찾아 삽입
			if (tmp->next != NULL && tmp->next->edge_index > edge_index) break;
			tmp = tmp->next;
		}
		newNode->next = tmp->next; // 노드를 리스트에 삽입
		tmp->next = newNode;
	}
}

// 특정 정점에 연결된 간선을 탐색
void search_vertex(Graph *graph, int vertex_index) {
	Node *node = graph->vertex[vertex_index].list; // 해당 정점의 연결 리스트
	Edge tmp;

	if (vertex_index < 0 || vertex_index > 5) { // 정점 범위 체크
		printf("-1\n");
		return;
	}

	while (node != NULL) { // 연결 리스트 탐색
		if (node->edge_index == -1) { // 더미 노드 건너뜀
			node = node->next;
			continue;
		}
		tmp = graph->edge[node->edge_index]; // 간선 정보 가져오기

		if (tmp.weight != 0) { // 가중치가 0이 아닌 경우 출력
			if (tmp.from == vertex_index + 1) 
				printf(" %d %d", tmp.to, tmp.weight);
			else 
				printf(" %d %d", tmp.from, tmp.weight);
		}

		node = node->next;
	}
	printf("\n");
}

// 간선을 수정하거나 추가/삭제
void modify_edge(Graph *graph, int vertex1_index, int vertex2_index, int weight) {
	int i, tmp;
	if ((vertex1_index < 0 || vertex1_index > 5) || (vertex2_index < 0 || vertex2_index > 5)) { // 정점 범위 체크
		printf("-1\n");
		return;
	}

	if (vertex1_index > vertex2_index) { // 정점 번호를 오름차순으로 정렬
		tmp = vertex1_index;
		vertex1_index = vertex2_index;
		vertex2_index = tmp;
	}

	for (i = 0; i < 21; i++) { // 간선 리스트 탐색
		if (graph->edge[i].from == vertex1_index + 1 && graph->edge[i].to == vertex2_index + 1) {
			if (graph->edge[i].weight == 0) { // 새 간선 추가
				graph->edge[i].weight = weight;
				add_node(&(graph->vertex[vertex1_index]), &(graph->vertex[vertex2_index]), i);
			} else 
				graph->edge[i].weight = weight; // 기존 간선 수정
			break;
		}
	}
}

int main() {
	Graph *graph;
	int i, vertex_num, vertex1, vertex2, weight;
	char func;

	graph = (Graph *)malloc(sizeof(Graph)); // 그래프 동적 메모리 할당
	graph->vertex = (Vertex *)malloc(sizeof(Vertex) * 6); // 정점 리스트 메모리 할당 : 문제 조건 정점이 6개임
	
	/*정점 6개인 그래프에서 가능한 간선 개수는, 
	자기 자신으로 가는 간선(즉, 루프)을 포함하여 최대 21(= 6 + 5 + 4 + 3 + 2 + 1)개다.*/
	graph->edge = (Edge *)malloc(sizeof(Edge) * 21); 
	

	for (i = 0; i < 6; i++) init_vertex(&(graph->vertex[i]), i + 1); // 정점 초기화
	init_edge(graph->edge, 6); // 간선 초기화

	// 간선 및 연결 리스트 초기화 : void add_edge(Edge *edge, int index, int weight)

	/*
	(1, 1) → 간선 번호 0
	(1, 2) → 간선 번호 1
	(1, 3) → 간선 번호 2
	...
	(1, 6) → 간선 번호 5 
	(2, 1) → 간선 번호 6 
	(2, 2) → 간선 번호 7 
	(2, 3) → 간선 번호 8 // 9
	(5, 6) → 간선 번호 19
	
	*/
	add_edge(graph->edge, 1, 1); // (1,2)
	add_edge(graph->edge, 2, 1); // (1,3)
	add_edge(graph->edge, 3, 1); // (1,4)
	add_edge(graph->edge, 5, 2); // (1,6)
	add_edge(graph->edge, 7, 1); // ()
	add_edge(graph->edge, 13, 4);
	add_edge(graph->edge, 18, 4);
	add_edge(graph->edge, 19, 3); // (5,6)

	// 정점 간 연결 리스트 초기화
	add_node(&(graph->vertex[1]), &(graph->vertex[2]), 7);
	add_node(&(graph->vertex[0]), &(graph->vertex[1]), 1);
	add_node(&(graph->vertex[0]), &(graph->vertex[2]), 2);
	add_node(&(graph->vertex[0]), &(graph->vertex[3]), 3);
	add_node(&(graph->vertex[0]), &(graph->vertex[5]), 5);
	add_node(&(graph->vertex[2]), &(graph->vertex[4]), 13);
	add_node(&(graph->vertex[4]), &(graph->vertex[4]), 18);
	add_node(&(graph->vertex[4]), &(graph->vertex[5]), 19);

	while (1) { // 사용자 입력 대기
		scanf("%c", &func);

		if (func == 'a') { // 정점 탐색
			scanf("%d", &vertex_num);
			getchar();
			search_vertex(graph, vertex_num - 1);
		} else if (func == 'm') { // 간선 수정
			scanf("%d %d %d", &vertex1, &vertex2, &weight);
			getchar();
			modify_edge(graph, vertex1 - 1, vertex2 - 1, weight);
		} else if (func == 'q') { // 종료
			break;
		} else 
			break;
	}
	return 0;
}
