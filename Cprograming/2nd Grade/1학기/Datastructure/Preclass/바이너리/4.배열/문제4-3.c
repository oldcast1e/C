#include <stdio.h>

void Arr_print(int arr[100][100],int num_N,int num_M) {
	int num1,num2, turn =1; //turn은 방향 바꾸어주는 변수, num은 반복횟수
	int count = 1; //1부터 n의 제곱까지 나타내주는 변수
	int col = 0, row = -1; //col은 행, row는 열
	num1 = num_N;num2 = num_M;
	while (num1!=0 && num2!=0) {
		for (int i = 0; i < num2; i++) { //행(가로)담당
			row += turn;//열을 증가/감소함
			arr[col][row] += count;//1,2,3,4,,,순으로 저장함
			count++;//count값 업데이트
		}
		num1--; //행/열의 출력이 끝나면 열/행의 반복횟수가 -1이 된다.
		for (int i = 0; i < num1; i++) {//열(세로)담당
			col += turn;//열 증가
			//이때 아까 출력했던 가로부분과 인덱스가 달라야하므로 열을 업데이트하고 값을 저장한다.
			arr[col][row] += count;
			count++;//count값 업데이트
		}
        num2 --; //행/열의 출력이 끝나면 열/행의 반복횟수가 -1이 된다.
		turn *= -1;//방향 전환
	}
	for (int i = 0; i < num_N; i++) {
		for (int j = 0; j < num_M; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	int n,m; //n*n배열의 n
	int arr[100][100] = { 0 };
	// printf("숫자를 입력하시오:"); //n의 크기 입력
	scanf("%d %d", &n,&m);// 두 값을 입력받고,
	Arr_print(arr, n,m);//출력 함수를 실행한다.
	return 0;
}

