#include <stdio.h>

int mostOnes(int A[][100], int n) {
	int row,cal;
	for (int j = 0; j < n; j++) {
		if (A[0][j] == 0) {
			cal = j;
			break;
		}
	}
	for (int i = 1; i < n; i++) {
    //printf("ar = %d\n", A[i][cal]);
        if (A[i][cal] == 1) {
            for (int j = cal+1; j < n; j++) {
                if ((A[i][j] == 0)||(j==n-1)) {
                    cal = j;
                    row = i;
                    break;
                }
            }
        }
	}
	return row;
}

int main() 
{
	int dnum[100][100];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &dnum[i][j]);
		}
	}

	int rst;
	rst = mostOnes(dnum,n);
	printf("%d", rst);

}
/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/