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


int main(void){
   char arrression[MAX_STACK_SIZE];//크기가 MAX_STACK_SIZE인 배열을 선언
   int num;scanf("%d",&num);//정수를 입력받음
   getchar();

   for(int i=0;i<num;i++){//입력받은 정수만큼 반복
      scanf("%s", arrression);//문자열을 입력받고
      int result2 = Cal(arrression);//수식 변환 함수를 실행 후 반환 값을 저장
      printf("%d\n",result2);
   }
   return 0;
}
/**
4 
53*2+63+2*+ 
234*+ 
72/3-42*+21*- 
923*1+2*+
 */