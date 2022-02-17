#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#define MAX_STACK_SIZE 100

int err = 0;  //에러가 발생했는지 체크하는 변수(0: 에러 없음, 1: 에러 발생)

// ===== 스택 코드의 시작 ===== 
typedef struct {
   char data[MAX_STACK_SIZE];
   //스택의 배열: 최대 용량은 100
   int num;//(현재 스택의 데이터 개수 - 1 )
} StackType;

// 스택 초기화 함수
void Initialize(StackType *s){s->num = -1;}
/**
현재 스택의 데이터 개수를 초기화한다.
이때 (현재 데이터 개수 -1)를 하는 이유는 배열의 인덱스 값으로 맞추기 위함이다.
 */

// 공백 상태 검출 함수
int IsEmpty(StackType *s){return (s->num == -1);}
// 포화 상태 검출 함수
int IsFull(StackType *s){return (s->num >= (MAX_STACK_SIZE - 1));}

// 삽입함수
void Push(StackType *s, char ipt){
   if (IsFull(s)) {
      printf("스택 포화 발생\n");
      return;
   }
   else s->data[++(s->num)] = ipt;
}
// 삭제함수
char Pop(StackType *s){
   if (IsEmpty(s)) {
      printf("스택 공백 발생: 프로그램을 종료합니다.");
      exit(1);
   }
   else return s->data[(s->num)--];
}
// 피크함수
char Peek(StackType *s){
   if (IsEmpty(s)) {
      printf("스택 공백 발생: 프로그램을 종료합니다.");
      exit(1);
   }
   else return s->data[s->num];
}
// ===== 스택 코드의 끝 ===== 

// 후위 표기 수식 계산 함수
int Cal(char arr[]){
   int op1, op2, value;
   char ch;
   StackType s;//스택을 선언

   Initialize(&s);//스택을 초기화

   for (int i = 0; i < (int)strlen(arr); i++) {
      //인자로 받은 배열 만큼 반복

      ch = arr[i];//현재 인덱스의 값을 저장
      
      // 입력이 피연산자이면 : 연산자가 아닌 값
      if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
         value = ch - '0';   
         Push(&s, value);
      }
      else {   
         //연산자이면 피연산자를 스택에서 제거
         op2 = Pop(&s);//op2에 저장 후 피연산자 삭제됨
         op1 = Pop(&s);//op1에 저장 후 피연산자 삭제됨

         switch (ch) { 
         //연산을 수행하고 스택에 저장 
         case '+': Push(&s, op1 + op2); break;
         case '-': Push(&s, op1 - op2); break;
         case '*': Push(&s, op1 * op2); break;
         case '/': Push(&s, op1 / op2); break;
         }
      }
   }
   return Pop(&s);
}

// 연산자의 우선순위를 반환한다.
int prec(char op)
{
   switch (op) {
   case '(': case ')': return 0;
   case '|': return 1;
   case '&': return 2;
   case '>': case '<': return 3;
   case '+': case '-': return 4;
   case '*': case '/': return 5;
   case '!': return 6;
   }
return -1;
}

//에러 확인 함수
void check_error(char arr[]) {
   int len = strlen(arr),count = 0;
   err = -1;//에러 확인 변수 초기화
   // (0: 에러 없음, 1: 에러 발생)

   // error 0 : / 연산자 후 0이 오면 예외처리
   for (int i = 0; i < len; i++) {
      if (i + 1 < len && arr[i] == '/' && arr[i + 1] == '0') {
         printf("<error 발생>>\n");
         printf("infix_to_postfix error0: divide by 0\n\n");
         err = 0;
         break;
      }
   }

   // error 1 : 괄호의 짝이 맞지 않으면 예외처리
   for (int i = 0; i < len; i++) {
      if (arr[i] == '(') {
         count++;
      }
      else if (arr[i] == ')') {
         count--;
      }
   }
   if (count > 0) {
      printf("<error 발생>>\n");
      printf("infix_to_postfix error1: 괄호 매칭 불가능\n\n");
      err = 1;
   }
   else if (count < 0) {
      printf("<error 발생>>\n");
      printf("infix_to_postfix error1: 괄호 매칭 불가능2\n\n");
      err = 1;
   }

   // error 2 : 예외 문자 포함
   for (int i = 0; i < len; i++) {
      if (arr[i] == '(' || arr[i] == ')') {
         continue;
      }
      //(조건 1)
      else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {
         continue;
      }
      //(조건 2)
      else if (arr[i] == '!' || arr[i] == '|' || arr[i] == '&' || arr[i] == '>' || arr[i] == '<') {
         continue;
      }
      //(조건3)
      else if ('A' <= arr[i] && arr[i] <= 'Z') {
         continue;
      }
      else {
         //조건 1,2를 만족하지 않는 경우
         printf("<error 발생: [%c]>\n",arr[i]);
         printf("infix_to_postfix error2: 예외 문자 포함\n\n");
         err = 2;
      }
   }

   // // error 3 : 한 자리 수 이상의 수 입력에 대해 예외 처리(예시: 23, 123, ...)
   // int count_len = 0;
   // int max_len = 0;
   // for (int i = 0; i < len; i++) {
   //    if ('0' <= arr[i] && arr[i] <= '9') {
   //       count_len++;
   //       if (count_len >= max_len) {
   //          max_len = count_len;
   //       }
   //    }
   //    else {
   //       count_len = 0;
   //    }
   // }
   // if (max_len >= 2) {
   //    printf("<error 발생>>\n");
   //    printf("infix_to_postfix error3: 한 자리수 이상의 입력 포함\n\n");
   //    err = 3;
   // }
}

// 수식 변환함수
char* infix_to_postfix(char arr[]){//배열을 반환한다.
   
   // 입력받은 표기식 에러 검사
   check_error(arr);
   // 에러가 있다면 다시 실행
   if (err != -1) {
      return NULL;
   }

   int i, idx = 0; //i는 for문의 제어변수, idx는 post_arr의 index
   int len = strlen(arr);
   char ch, op;

   StackType s;//스택 선언

   char* stack_arr = (char*)malloc(MAX_STACK_SIZE);//배열을 동적할당한다.
   if (stack_arr == NULL) {//동적할당 실패 시
      printf("메모리 할당 에러\n");
      exit(1);
   }

   Initialize(&s);  //스택 초기화

   // 중위 표기식으로 표현된 식을 순회
   for (int i = 0; i < len; i++){
      // 값을 뽑는다
      ch = arr[i];

      /*값 확인*/

      // 일반 숫자라면 그대로 stack_arr에 추가
      if ('A' <= ch && ch <= 'Z') {
         stack_arr[idx++] = ch;
      }

      // 연산자 +,-,*,/라면
      else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '>' || ch == '<' || ch == '!' ||ch == '|' || ch == '&' ) {
         // 스택의 num 값이 현재 연산자보다 우선순위가 높다면
         while (!IsEmpty(&s) && (prec(ch) <= prec(Peek(&s)))){
            // 해당 값들은 모두 추가해준다.
            if(ch == '|' || ch == '&' ){
               int tmp1,tmp2;
               stack_arr[idx++] = tmp1 =  Peek(&s);
               // stack_arr[idx++] = tmp2 = Peek(&s);
               // printf("<추가: %c%c>\n",tmp1,tmp2);
               Pop(&s);
            }
            else{
               stack_arr[idx++] = Peek(&s);
               Pop(&s);
            }
         }
         // 자기자신을 스택에 추가한다.
         if(ch == '|' || ch == '&' ){
            i++;
            Push(&s, ch);
            Push(&s, ch);
         }
         else{
            Push(&s, ch);
         }
         // Push(&s, ch);
      }

      // else if (ch == '|' || ch == '&' ) {
      //    printf("check[%d]: %c\n",i,ch);
      //    // 스택의 num 값이 현재 연산자보다 우선순위가 높다면
      //    while (!IsEmpty(&s) && (prec(ch) <= prec(Peek(&s)))){
      //       // 해당 값들은 모두 추가해준다.
      //       int tmp1,tmp2;
      //       stack_arr[idx++] = tmp1 =  Peek(&s);
      //       stack_arr[idx++] = tmp2 = Peek(&s);
      //       printf("<추가: %c%c>\n",tmp1,tmp2);
      //       Pop(&s);
      //    }
      //    i ++;
      //    // 자기자신을 스택에 추가한다.
      //    Push(&s, ch);
      // }
      // '('는 무조건 스택에 추가한다.
      else if (ch == '(') {
         Push(&s, ch);
      }

      // ')'가 나오면 '('가 나올때 까지 스택에서 Pop하여 추가해준다.
      else if (ch == ')') {
         op = Pop(&s);
         while (op != '('){
            stack_arr[idx++] = op;
            op = Pop(&s);
         }
      }
   }

   //아직 스택에 남아있는 값들을 모두 추가해준다.
   while (!IsEmpty(&s)) {
      op = Peek(&s);
      Pop(&s);
      stack_arr[idx++] = op;
   }

   // 문자열의 끝을 지정해준다.
   stack_arr[idx] = '\0';
   return stack_arr;
}

int main(void){
   char arrression[MAX_STACK_SIZE];//크기가 MAX_STACK_SIZE인 배열을 선언
   int num;scanf("%d",&num);//정수를 입력받음
   getchar();

   for(int i=0;i<num;i++){//입력받은 정수만큼 반복
      scanf("%s", arrression);//문자열을 입력받고

      char *result = infix_to_postfix(arrression);//수식 변환 함수를 실행 후 반환 값을 저장
      if (err == -1) {
         printf("%s\n", result);
      }
   }
   return 0;
}
/**
 * 
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)

answer
AB*C+DE+F*+    -> AB*C+DE+F*+
ABC*+    -> ABC*+
AB/C-DE*+FG*- ->  AB/C-DE*+FG*-
ABC*D+E*+ ->   ABC*D+E*+
AB&&C||EF>!||  -> AB&&C||EF>!||
 */