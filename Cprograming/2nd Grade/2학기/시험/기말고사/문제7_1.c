#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    // int n; scanf("%d",&n);
    

}

/*

아래 조건을 다시 분석하고, 의사코드를 참고해 다시 코드를 작성해.

n개의 정점과 m개의 간선으로 이루어진 그래프 G에 대해
모든 임의의 두 정점 u와 v사이에 도달 가능한 경로가 존재할 때, G는 강연결이라고 하자.
방향그래프와 강연결성을 판별하는 C 프로그램을 작성해야한다.

- 주어진 그래프는 방향 그래프이며 DFS 이용해 강연성을 판별
- 입력 그래프는 n ( 1 <= n <= 100)개의 정점과 m( 1 <= n <= 1000)개의 간선으로 구성
- 각 정점은 1~n 사이의 정수로 번호, 정점의 번호는 모두 다름
- 강연결인 경우 1을 출력하고, 강연결이 아닌 경우 0을 출력해야함.

Alg DFS(G)
Input: graph G
    Output: labeling of the edges of G as tree edges and back edges {The algorithm uses a mechanism for setting and getting “labels” of vertices and edges}
    1. for each u ∈ G.vertices()
        l(u) <- Fresh
    2. for each e ∈ G.edges()
        l(e) <- Fresh
    3. for each v ∈ G.vertices()
        if (l(v) = Fresh)
                rDFS(G, v)

Alg rDFS(G, v)
    Input: graph G and a start vertex v of G
    Output: labeling of the edges of G in the connected component of v as tree edges and back edges
    1. l(v) <- Visited
    2. for each e ∈ G.incidentEdges(v)
        if (l(e) = Fresh)
                w <- G.opposite(v, e)
                if (l(w) = Fresh)
                    l(e) <- Tree
                    rDFS(G, w)
                else
                    l(e) <- Back

입력 예시
5 5
3 1
3 4
3 5
5 2
2 3

출력 예시 : 
0
설명:  -> 강연결이 아님 (4->3이 도달 불가능)




A -> B
A -> D
A - >E
B-> C
B->F
D -> E
D ->G
D -> I
G->E
E -> C
E -> H
H -> I
I ->F

깊이 우선탐색 시 정점 순회 순서 A -> B -> C -> F -> I -> H -> E -> G -> D
너비우선탐색 시 정점 순회 순서 A -> B -> F -> I -> D -> E -> G -> C -> H
위상 순서 A -> B -> C -> F -> D -> E -> G -> H -> I

으로 방향 그래프가 구성될때 A를 시작점으로 
1. 깊이우선탐색 시 정점 순회 순서
2. 너비우선탐색 시 정점 순회 순서
3. 위상 순서
*/