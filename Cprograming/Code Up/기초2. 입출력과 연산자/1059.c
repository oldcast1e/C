#include <stdio.h>

void binary_print(int a)
{
	int n = sizeof(int) * 8;	// 전체 비트 수
    int mask = 1 << (n-1);		// n개 비트 중 가장 최상위 비트만 1인 마스크에요.
    
    // 2^(n-1) 자리의 비트부터 2^0까지 n개 비트를 반복해요
    for (int i = 1; i <= n; i++)
    {
    	printf((a & mask) ? '1' : '0');
        
        // 이진수로 출력할 숫자값을 왼쪽으로 한칸씩 밀어 저장해요.
        // 마스크 값이 n개 비트 중 가장 최상위 비트에만 있기 때문이에요.
        a <<= 1;
        if (i % 8 == 0 && i < n)
        	printf(' ');	// 가독성을 위해, 8개 비트마다 끊어서 표기해요.
    }
    printf('\n');      // 개행문자를 마지막에 붙여줘요.
}

int main(void)
{
    printf("2진수로 나타낼 정수를 입력하세요.\n> ");
    int i;
    scanf("%d", &i);
    binary_print(i);
    return 0;
}