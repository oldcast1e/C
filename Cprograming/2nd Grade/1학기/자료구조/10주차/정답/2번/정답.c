#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, sign;

void push(int *arr, int ch) {
	top++;
	arr[top] = ch;
}

int pop(int *arr) {
	int data;
	data = arr[top];
	top--;
	return data;
}

int order(char op) {
	switch (op) {
    	case '+': return 1;
    	case '-': return 2;
    	case '*': return 3;
    	case '/': return 4;
    	default: return 0;
	}
}

void evaluate(char *arr){
	int sta[101] = { 0 };
	int num1, num2;
	for (int i = 0; i < strlen(arr); i++) {
		if (order(arr[i]) == 0)
			push(sta, arr[i] - '0');
			
		else if (order(arr[i]) == 1) {
			num1 = pop(sta);
			num2 = pop(sta);
			push(sta, num1 + num2);
		}
		else if (order(arr[i]) == 2) {
			num1 = pop(sta);
			num2 = pop(sta);
			push(sta, num2 - num1);
		}
		else if (order(arr[i]) == 3) {
			num1 = pop(sta);
			num2 = pop(sta);
			push(sta, num2 * num1);
		}
		else if (order(arr[i]) == 4) {
			num1 = pop(sta);
			num2 = pop(sta);
			push(sta, num2 / num1);
		}
	}
	printf("%d\n", pop(sta));
}
int main() {
	char str[101] = { NULL };
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		top = -1;
		sign = 0;
		gets(str);
		evaluate(str);
	}
}

