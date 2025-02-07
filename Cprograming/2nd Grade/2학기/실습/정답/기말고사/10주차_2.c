/*
[ 문제 2 ] (인접행렬 구현) 그림 1의 무방향 가중그래프를 인접행렬로 표현하고, 명령어에 따라
그래프 정보를 인쇄하거나 그래프를 수정하는 프로그램을 작성하시오. 명령어 정의와
입출력 예시는 문제 1과 같다.
*/

#include<stdio.h>
#include<stdlib.h>

// 정점(Vertex)을 정의하는 구조체
typedef struct Vertex {
	int name; // 정점의 이름
}Vertex;

// 간선(Edge)을 정의하는 구조체
typedef struct Edge {
	int weight; // 간선 가중치
	int start, end; // 간선의 시작 정점과 끝 정점
}Edge;

// 그래프(Graph)를 정의하는 구조체
typedef struct Graph {
	Vertex *vertex; // 정점 리스트
	Edge *edge;     // 간선 리스트
	int **matrix;   // 인접 행렬 (간선 정보 저장)
}Graph;

// 특정 간선 번호를 찾는 함수
int findEdgeNum(Graph *g, int a, int b) {
	//그래프의 간선의 시작점이 a이고 , 그래프의 간선의 끝점이 b인 간선 번호를 반환
	for (int i = 0; i < 21; i++) { //최대 21개의 간선(Edge)을 확인
		if (g->edge[i].start == a && g->edge[i].end == b)  return i; 
		
	}
}

// 인접 행렬을 초기화하는 함수
void initMatrix(Graph *g, int a, int b, int weight) {
	int n1, n2, edgeNum;

	// 정점 번호를 작은 번호가 앞에 오도록 정렬
	if (a < b) {n1 = a;n2 = b; }
	else {n1 = b;n2 = a; }

	edgeNum = findEdgeNum(g, n1, n2);//간선의 시작점이 n1이고 끝점이 n2인 간선의 번호를 edgeNum에 저장
	
	// 간선 가중치 설정
	g->edge[edgeNum].weight = weight;
	
	// 인접 행렬 업데이트
	g->matrix[a - 1][b - 1] = edgeNum;
	g->matrix[b - 1][a - 1] = edgeNum;
}

// 특정 정점에 연결된 간선을 탐색하고 출력하는 함수
void search(Graph *g, int n) {
	int edgeNum, i;

	// 유효하지 않은 정점 번호 처리
	if (n > 6 || n <= 0) {
		printf("-1"); // 에러 출력
		return;
	}

	// 해당 정점과 연결된 간선 탐색
	for (i = 0; i < 6; i++) {
		edgeNum = g->matrix[n - 1][i]; // 인접 행렬에서 간선 번호 확인

		if (edgeNum == -1) continue; // 간선이 없으면 건너뜀
		if (g->edge[edgeNum].start == n) {
			// 간선의 시작 정점이 현재 정점일 경우
			printf("%d %d ", g->edge[edgeNum].end, g->edge[edgeNum].weight);
		}
		else if (g->edge[edgeNum].end == n) {
			// 간선의 끝 정점이 현재 정점일 경우
			printf("%d %d ", g->edge[edgeNum].start, g->edge[edgeNum].weight);
		}
	}
}

// 간선을 수정하거나 삭제하는 함수
void modify(Graph *g, int a, int b, int weight) {
	int edgeNum, n1, n2;

	// 유효하지 않은 정점 번호 처리
	if ((a > 6 || a <= 0) || (b > 6 || b <= 0)) {
		printf("-1\n"); // 에러 출력
		return;
	}

	// 정점 번호를 작은 번호가 앞에 오도록 정렬
	if (a < b) {
		n1 = a;
		n2 = b;
	}
	else {
		n1 = b;
		n2 = a;
	}

	// 간선 번호 찾기
	edgeNum = findEdgeNum(g, n1, n2);
	if (weight == 0) { 
		// 가중치가 0이면 간선을 삭제
		weight = -1; // 삭제 표시 (-1)
		g->matrix[a - 1][b - 1] = -1; // 인접 행렬 업데이트
		g->matrix[b - 1][a - 1] = -1;
	}
	else {
		// 간선이 존재하지 않으면 추가, 존재하면 가중치 변경
		g->matrix[a - 1][b - 1] = edgeNum;
		g->matrix[b - 1][a - 1] = edgeNum;
	}
	g->edge[edgeNum].weight = weight; // 간선 가중치 설정
}

int main() {
	int i, j, tmp = 0, n1, n2, weight;
	char operation;
	Graph *g = (Graph *)malloc(sizeof(Graph)); // 그래프 동적 메모리 할당

	g->vertex = (Vertex *)malloc(sizeof(Vertex) * 6); // 정점 리스트 메모리 할당
	g->edge = (Edge *)malloc(sizeof(Edge) * 21); // 간선 리스트 메모리 할당

	g->matrix = (int **)malloc(sizeof(int *) * 21); // 인접 행렬 동적 할당

	for (i = 0; i < 6; i++) {
		g->matrix[i] = (int *)malloc(sizeof(int) * 6); // 각 행 동적 할당
		for (j = 0; j < 6; j++) {
			g->matrix[i][j] = -1; // 초기값 -1 설정 (간선 없음)
		}
	}

	// 정점 초기화
	for (i = 0; i < 6; i++) {
		g->vertex[i].name = i + 1; // 정점 ID 설정
	}

	// 간선 초기화
	for (i = 0; i < 6; i++) {
		for (j = i; j < 6; j++) {
			g->edge[tmp].start = i + 1; // 간선 시작 정점
			g->edge[tmp].end = j + 1;   // 간선 끝 정점
			tmp++;
		}
	}

	// 간선 정보 설정
	initMatrix(g, 1, 2, 1);
	initMatrix(g, 1, 3, 1);
	initMatrix(g, 1, 4, 1);
	initMatrix(g, 1, 6, 2);
	initMatrix(g, 2, 3, 1);
	initMatrix(g, 3, 5, 4);
	initMatrix(g, 5, 5, 4); // 자기 자신으로 가는 루프
	initMatrix(g, 5, 6, 3);

	// 사용자 입력에 따라 동작
	while (1) {
		scanf("%c", &operation); // 명령어 입력

		if (operation == 'a') { 
			// 정점 탐색
			scanf("%d", &n1);
			getchar();
			search(g, n1);
			printf("\n");
		}
		else if (operation == 'm') { 
			// 간선 수정
			scanf("%d %d %d", &n1, &n2, &weight);
			getchar();
			modify(g, n1, n2, weight);
		}
		else if (operation == 'q') { 
			// 종료
			return 0;
		}
	}
}
