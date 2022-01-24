#include <stdio.h>

int main() {
	char ans[3], u, inp[3] = { '_','_','_' };//정답을 입력받을 배열과 정답을 맞추는 배열 선언
	for (int i = 0; i < 3; i++)//3번 반복하여
		scanf("%c", &ans[i]);//정답을 입력받고
	getchar();//엔터키를 없앤다
	for (int i = 0; i < 5; i++) {//5번 반복하여
		scanf("%c", &u);//값을 입력받고
		getchar();//스페이스 값을 없애고

		for (int j =0; j < 3; j++) {//3번 반복하요
			if (u == ans[j])//정답과 일치하는지 비교
				inp[j] = u;//일치하는게 있으면 해당 요소의 순서에 입력값 대입
		}
		for (int j =0; j < 3; j++)
			printf(" %c", inp[j]);//현재까지 입력한 값 출력
		printf("\n");//줄띄움
		if (ans[0] == inp[0] && ans[1] == inp[1] && ans[2] == inp[2]) break;//모두 일치 하는 경우 반복 종료
	}
}
