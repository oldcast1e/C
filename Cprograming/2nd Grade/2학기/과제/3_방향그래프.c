#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// #define MAX 30 // 최대 도시 수
#define MAX 15 // 최대 도시 수

//정방향 버전 채택

// airtelDC: 분할정치법 재귀 구현
int airtelDCRecursive(int s, int d, int A[], int H[]) {
    if (s == d) {return 0;} // 같은 도시 : 비용 0

    int minCost = INT_MAX;
    for (int k = s; k < d; k++) {
        int cost = airtelDCRecursive(s, k, A, H) + H[k] + A[d - k];
        if (cost < minCost) {minCost = cost;}
    }

    return minCost;
}

// airtelDP: 동적 프로그래밍 구현
int airtelDP(int n, int s, int d, int A[], int H[]) {
    int m[MAX][MAX];

    // 비용 배열 초기화
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {m[i][j] = INT_MAX;}
        m[i][i] = 0; // 같은 도시의 비용은 0
    }

    // 최소 비용 계산:동적 프로그래밍
    for (int length = 1; length < n; length++) {
        for (int start = 0; start + length < n; start++) {
            int end = start + length;
            for (int k = start; k < end; k++) {
                int cost = m[start][k] + H[k] + A[end - k];
                if (cost < m[start][end]) {
                    m[start][end] = cost;
                }
            }
        }
    }

    return m[s][d];
}

// 실행 시간 측정
double getCPUTime() {return (double)clock() / CLOCKS_PER_SEC * 1000.0;}

int main() {
    int A[MAX], H[MAX];
    /*
    {initialize A and H}
    1. A[0], A[1] ← 0, 1
    2. for i ← 2 to MAX – 1
        A[i] ← A[i – 1] + A[i – 1]%5 + 3 
        {A = {0, 1, 5, 8, 14, 21, 25, 28, 34, 41, ...}}
    3. H[0], H[1] ← 0, 5
    4. for i ← 2 to MAX – 1
        H[i] ← (H[i – 1] + i)%9 + 1 {H = {0, 5, 8, 3, 8, 5, 3, 2, 2, 3, 5, 8, ...}}
    5. print “n”, “s”, “d”, “mincost”, “version”, “cputime“ {print header}
    */
    
    A[0] = 0; A[1] = 1;//초기 배열 생성 조건 1
    for (int i = 2; i < MAX; i++) {A[i] = A[i - 1] + i + A[i - 1] % 5 + 3; }//초기 배열 생성 조건 2
    H[0] = 0; H[1] = 5;//초기 배열 생성 조건 3
    for (int i = 2; i < MAX; i++) {H[i] = (H[i - 1] + i) % 9 + 1;}//초기 배열 생성 조건 4
    printf("n    s    d\tmincost\t  version   cputime\n");//초기 배열 생성 조건 5


    /*
    {Test run for mini input}
    5. n ← 6
    6. for (s, d) in {(0, 4), (2, 5), (2, 4)} {run three (s, d) pairs for test}
    airtelDC(n, s, d)
    printCPUTime() {print n, s, d, mincost, version, cputime}
    airtelDP(n, s, d)
    printCPUTime() {print n, s, d, mincost, version, cputime}
    */
    int n = 6; // Test run for mini input 조건 5
    int s, d; // Test run for mini input 조건 6
    double start, end;
    int minCostDC,minCostDP;
    s = 0; d = 4;

    // airtelDC (분할정치법)
    start = getCPUTime();
    minCostDC = airtelDCRecursive(s, d, A, H);
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DC\t    %.6f ms\n", n, s, d, minCostDC, end - start);

    // airtelDP (동적 프로그래밍)
    start = getCPUTime();
    minCostDP = airtelDP(n, s, d, A, H);
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DP\t    %.6f ms\n", n, s, d, minCostDP, end - start);

    /*------------------------------------*-------------------------------------*/
    s = 2; d = 5;

    // airtelDC (분할정치법)
    start = getCPUTime();
    minCostDC = airtelDCRecursive(s, d, A, H);
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DC\t    %.6f ms\n", n, s, d, minCostDC, end - start);

    // airtelDP (동적 프로그래밍)
    start = getCPUTime();
    minCostDP = airtelDP(n, s, d, A, H);
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DP\t    %.6f ms\n", n, s, d, minCostDP, end - start);
    /*----------------------------------------------*-----------------------------------------*/
    s = 2; d = 4;

    // airtelDC (분할정치법)
    start = getCPUTime();
    minCostDC = airtelDCRecursive(s, d, A, H);
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DC\t    %.6f ms\n", n, s, d, minCostDC, end - start);

    // airtelDP (동적 프로그래밍)
    start = getCPUTime();
    minCostDP = airtelDP(n, s, d, A, H);
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DP\t    %.6f ms\n", n, s, d, minCostDP, end - start);
    /*----------------------------------------------*-----------------------------------------*/

    /*
    {Main run for big input}
    7. n ← MAX
    8. s, d ← 1, n – 2 {an (s, d) pair for test}
    9. airtelDC(n, s, d)
    10. printCPUTime() {print n, s, d, mincost, version, cputime}
    11. airtelDP(n, s, d)
    12. printCPUTime() {print n, s, d, mincost, version, cputime}
    */
    n = MAX; //Main run for big input 조건 7
    s = 1; d = n - 2; //Main run for big input 조건 8

    // airtelDC
    start = getCPUTime();
    minCostDC = airtelDCRecursive(s, d, A, H); //Main run for big input 조건 9
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DC\t    %.6f ms\n", n, s, d, minCostDC, end - start); //Main run for big input 조건 10

    // airtelDP
    start = getCPUTime();
    minCostDP = airtelDP(n, s, d, A, H); //Main run for big input 조건 11
    end = getCPUTime();
    printf("%-5d%-5d%-5d\t%d\t  DP\t    %.6f ms\n", n, s, d, minCostDP, end - start);//Main run for big input 조건 12

    return 0;
}
