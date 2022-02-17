// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// /*스택을 구현하는 구조체*/
// typedef struct {
//     int max; //스택용량
//     int num; //스택에 쌓여있는 데이터의 개수(스택 포인터)
//     char *stk;//스택의 첫 요소에 대한 포인터
// }CharStack;

// /*스택 초기화*/
// int Initialisze(CharStack *stt,int max){
//     stt->num = 0;
//     stt->stk = malloc(max*sizeof(char));
//     /*
//     인자로 받은 스택 용량 만큼,
//     인자로 받은 배열이 가리키는 스택의 첫 요소에 대한 포인터를 동적할당한다.
//     */

//     //동적할당 실패 시
//     if((stt->stk)==NULL){stt->max = 0;return -1;}

//     //동적할당 성공 시
//     stt->max = max;
//     return 0;
// }

// /*스택에 데이터를 푸시*/
// int Push(CharStack *stt,char data){
//     if(stt->num >= stt->max) return -1;
//     //인자로 받은 배열의 스택에 쌓여있는 데이터의 개수가 용량보다 크거나 같으면 종료

//     stt->stk[stt->num ++] = data;
//     //인자로 받은 배열이 가리키는 배열의 num인덱스에 해당하는 공간에 데이터를 저장
//     //이후 인덱스를 증가시킴
//     return 0;
// }

// /*스택에 데이터를 팝 == 꺼냄*/
// int Pop(CharStack *stt,char *del){
//     if(stt->num <= 0) return -1;
//     //스택에서 꺼낼 수 있는 수가 0보다 작거나 같으면 종료
    
//     *del = stt->stk[stt->num --];
//     //인자로 받은 배열이 가리키는 배열의 num 인덱스에 해당하는 데이터 값을 포인터 del의 참조값으로 저장
//     //이후 인덱스를 감소하고 종료
//     return 0;
// }

// /*스택에서 데이터를 피크 == 확인*/
// int Peek(CharStack *stt,char *pek){
//     if(stt->num <= 0) return -1;
//     //스택에서 꺼낼 수 있는 수(== 확인할 데이터 값)가 0보다 작거나 같으면 종료
//     *pek = stt->stk[stt->num -1];
//     //인자로 받은 배열이 가리키는 배열의 (num-1) 인덱스에 해당하는 값을 포인터 pek의 참조값을 저장
//     return 0;
// }

// /*스택 비우기*/
// void Clear(CharStack *stt){
//     stt->num = 0;
//     //스택의 개수를 0으로 초기화 -> 검사할 수 있는 스택이 0이 됨.
//     //이때 스택의 개수와 스택의 최대 용량은 다르다!
// }

// /*스택의 최대 용량*/
// int Capacity(CharStack *stt){return stt->max;}
// //스택의 최대 용량을 반환

// /*스택의 데이터 개수*/
// int Size(CharStack *stt){return (stt->num);}

// /*스택이 비어있는지의 유무*/
// int isEmpty(CharStack *stt){
//     return (stt->num <= 0);
//     //스택의 데이터 개수가 0보다 작거나 같으면 1
//     //스택의 데이터 개수가 0보다 크면 1

//     //스택이 비어있으면(데이터 개수가 0 이하) 1을 반환
// }

// /*스택이 가득 찼는지의 유무*/
// int isFull(CharStack *stt){
//     return( stt-> num >= stt->max);
//     //스택의 데이터 개수가 스택의 최대 용량보다 많으면 1 반환
//     //스택의 데이터 개수가 스택의 최대 용량보다 적으면 0 반환
// }

// /*스택에서의 검색*/
// int Search(CharStack *stt,char key){
//     //스택의 개수만큼 꼭대기에서 부터 선형 검색
//     for(int i=(stt->num)-1;i>=0;i--){
//         if(key == stt->stk[i]) return i;
//         /**
//         인자로 받은 검색값과 일치하는 
//         stt가 가리키는 배열의 데이터가 있을 시 해당 인덱스 반환
//          */
//     }
//     return - 1;
// }

// /*스택의 모든 데이터 출력*/
// void Print(CharStack *stt){
//     for(int i=0;i<stt->num;i++) printf("%d ",stt->stk[i]);
//     //스택의 데이터 수 만큼 반복하여 스택의 데이터를 출력
//     printf("\n");
// }

// /*스택 종료*/
// void Terminate(CharStack *stt){
//     if(stt->stk != NULL) free(stt->stk);
//     //스택의 배열이 NULL이 아닌 경우 스택의 동적할당된 배열을 해제

//     stt->max = stt->num = 0 ;
//     //스택의 최대 용량과 스택의 데이터 수를 0으로 초기화
// }
// /**
// 1. 숫자가 나오면 그대로 출력한다.
// 2/ (이 나오면 스택에 push한다.
// 3.* / 나오면 스택에 push한다.
// 4. + - 연산이 나오면 여는 괄호('('), 여는 괄호가 없다면 스택의 끝까지 출력하고 그 연산자를 스택에 push한다.
// 5. 닫는 괄호( ')' )가 나오면 여는 괄호( '(' )가 나올때까지 pop하여 출력한다.

// ++ 논리연산 확인!

// 스택은 배열이나 연결리스트로 구현함
// 수식의 피연산자는 영문자(대문자)로 나타내고, 각 수식의 최대길이는 100으로 함
// 수식은 아래 우선순위를 갖는 연산자들을 포함함 (숫자가 높을수록 우선순위가 높음)

// 1. 숫자가 나오면 그대로 출력한다.
// 2. (나오면 스택에 push한다.
// 3. * / 나오면 스택에 push한다.
// 4. + - 연산이 나오면 여는 괄호('('), 
//     여는 괄호가 없다면 스택의 끝까지 출력하고 그 연산자를 스택에 push한다.
// 5. 닫는 괄호(')')가 나오면 여는 괄호('(')가 나올때까지 pop하여 출력한다.
//  */
// int main() {
//     int num,key;scanf("%d",&num);//수식의 개수
//     getchar();
//     char tmp[101];

//     for(int i=0;i<num;i++){
//         gets(tmp);
//         CharStack stack; Initialisze(&stack,strlen(tmp));
//         //스택의 배열을 동적할당: 문자열의 길이만큼

//         for(int j=0;j<(int)strlen(tmp);j++){
//             if('0' <= tmp[j] && tmp[j] <= '9') printf("%c",tmp[j]);
//             else if(tmp[j] == '(') Push(&stack,tmp[j]);//(나오면 스택에 push한다.
//             else if(tmp[j] == '*' || tmp[j] == '/') Push(&stack,tmp[j]);//* / 나오면 스택에 push한다.
//             // else if(tmp[j] == '+'||tmp[j] == '-'){
//             //     key = 0;
//             //     for(int k=0;k<stack.num;k++){
//             //         printf("%c",stack.stk[k]);
//             //         Pop(&stack,&stack.stk[k]);
//             //     }
//             //     Push(&stack,tmp[j]);

//             // }
//         }
//         Terminate(&stack);
//         /**
//         1+2*3+(4+2)/2
//          */


//     }

    #include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {


}	



// }	