#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int top=-1, sign=0;

void push(char stack[],char data) {
	top++;
	stack[top] = data;
}

char pop(char stack[]) {
	char data= stack[top];
	top--;
	return data;
}

int order(char ar[],int i) {
	if ((top != i) && (i == 0) && ((ar[i] == '+') || (ar[i] == '-'))) {
		sign = 1;
		return 6;
	}
	else if ((top != -1) && ((ar[i] == '+') || (ar[i] == '-')) &&
		((ar[i - 1] == '|') || (ar[i - 1] == '&') || (ar[i - 1] == '<') ||
		(ar[i - 1] == '>') || (ar[i - 1] == '-') || (ar[i - 1] == '+') ||
		(ar[i - 1] == '*') || (ar[i - 1] == '/') || (ar[i - 1] == '!'))) 
		return 6;

	else if (ar[i] == '|') {
		return 1;
	}
	else if (ar[i] == '&') {
		return 2;
	}
	else if ((ar[i] == '>')||(ar[i]=='<')) {
		return 3;
	}
	else if ((ar[i] == '+') || (ar[i] == '-')) {
		return 4;
	}
	else if ((ar[i] == '*') || (ar[i] == '/')) {
		return 5;
	}
	else if ((ar[i] == '!')) {
		return 6;
	}
	else return 0;
}

void trans(char *ar) {
	char stack[101] = {NULL};

	for (int i = 0; i < strlen(ar); i++) {
		if (ar[i] == '(') {
			push(stack, ar[i]);
		}else if (ar[i] == ')') {
			while (stack[top] != '(') {
				printf("%c", pop(stack));
			}
			pop(stack);
		}
		else if (order(ar,i) == 6) {
			push(stack, ar[i]);
		}
		else if (order(ar, i) == 0) printf("%c", ar[i]);
		else {
			if (sign == 1) printf("%c", pop(stack));
			else {
				while ((top != -1) && (order(ar, i) <= order(stack, top))) {
					printf("%c", pop(stack));
				}
			}
			if ((order(ar, i) == 1) || (order(ar, i) == 2)) {
				push(stack, ar[i]);
				i++;
			}
			push(stack, ar[i]);
		}
	}
	while (top != -1) {
		printf("%c", pop(stack));
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char ar[101] = { NULL };
		top = -1;
		sign = 0;
		gets(ar);
		trans(ar);
	}
	return 0;
}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)
*/