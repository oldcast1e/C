#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack {
   char *Stack;
   int size;
   int num;
}STACK;

STACK *initStack() {
   STACK *stack;
   stack = (STACK *)malloc(sizeof(STACK));
   stack->Stack = NULL;
   stack->size = 0;
   stack->num = -1;
}
void push(STACK *stack, char data) {
   stack->num++;
   stack->Stack[stack->num] = data;
}
char pop(STACK *stack) {
   stack->num--;
   return stack->Stack[stack->num + 1];
}
void peek(STACK *stack) {
   printf("%c", stack->Stack[stack->num]);
}
void duplicate(STACK *stack) {
   char tmp1;
   tmp1 = pop(stack);
   push(stack, tmp1);
   push(stack, tmp1);
}
void upRotate(STACK *stack, int n) {
   char tmp;
   tmp = stack->Stack[stack->num];
   for (int i = stack->num; i > stack->num - n + 1; i--) {
      stack->Stack[i] = stack->Stack[i - 1];
   }
   stack->Stack[stack->num - n + 1] = tmp;
}
void downRotate(STACK *stack, int n) {
   char tmp;
   tmp = stack->Stack[stack->num - n + 1];
   for (int i = stack->num - n + 1; i < stack->num; i++) {
      stack->Stack[i] = stack->Stack[i + 1];
   }
   stack->Stack[stack->num] = tmp;
}
void print(STACK *stack) {
   for (int i = stack->num; i >= 0; i--) {
      printf("%c", stack->Stack[i]);
   }
   printf("\n");
}

int main() {
   STACK *stack = initStack();
   int s_num, N, n;
   char order[6] = { NULL };
   char ch;
   scanf("%d", &s_num);
   scanf("%d", &N);
   getchar();
   stack->Stack= (char *)malloc(sizeof(char) * s_num);
   stack->size = s_num - 1;
   for (int i = 0; i < N; i++) {
      scanf("%s", order);
      getchar();
      if (strcmp(order, "PUSH") == 0) {
         scanf("%c", &ch);
         getchar();
         if (stack->num == stack->size) {
            printf("Stack FULL\n");
            continue;
         }
         push(stack, ch);
      }
      else if (strcmp(order, "POP") == 0) {
         if (stack->num == -1) {
            printf("Stack Empty\n");
            continue;
         }
         ch = pop(stack);
      }
      else if (strcmp(order, "PEEK") == 0) {
         if (stack->num == -1) {
            printf("Stack Empty\n");
            continue;
         }
         peek(stack);
      }
      else if (strcmp(order, "DUP") == 0) {
         if (stack->num == stack->size) {
            printf("Stack FULL\n");
            continue;
         }
         duplicate(stack);

      }
      else if (strcmp(order, "UpR") == 0) {
         scanf("%d", &n);
         getchar();
         if (n > stack->num + 1) continue;
         upRotate(stack, n);
      }
      else if (strcmp(order, "DownR") == 0) {
         scanf("%d", &n);
         getchar();
         if (n > stack->num + 1) continue;
         downRotate(stack, n);
      }
      else if (strcmp(order, "PRINT") == 0) {
         print(stack);
      }

   }
   return 0;
}

