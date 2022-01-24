// #include  <stdio.h>
// #include  <string.h>
// #include  <stdlib.h>
// int main(){

//     int N,num[100],cnt;
//     for(int i=0;i<100;i++)num[i] =0;
//     char X[101],arr[100];
    
//     scanf("%d %s",&N,X);getchar();
//     //문자형 포인터 배열 Y
//     char *Y[100];
//     for(int i=0;i<N;i++){
//         gets(arr);
//         Y[i] = (char*)malloc((int)strlen(arr)*sizeof(char));
//         if(Y[i]== NULL){
//             printf("Error");
//             return -1;
//         }
//         // 동적 할당 시 정상적으로 메모리 할당이 되었는지를 체크
//         strcpy(Y[i],arr);strcat(Y[i],"\0");
//         printf(">%s\n",Y[i]);
//         //N 줄의 공백을 포함하는 문자열을 입력받아, 
//         //동적으로 저장 장소를 할당 받은 후 문자형 포인터 배열 Y에 연결한다. 
//         printf("strlen(Y[i]) = %d | strlen(X) = %d | strlen(Y[i])-strlen(X) = %d\n",(int)strlen(Y[i]),(int)strlen(X),(int)strlen(Y[i])-(int)strlen(X));
//         for(int j=0;j <= ((int)strlen(Y[i])-(int)strlen(X));j++){//13-3=10
//             cnt = 0;
//             for(int k=0;k<(int)strlen(X);k++){
//                 // printf(">%d %d\n",j,k);
//                 // printf(">>%d %d\n",j+k,k);
//                 // printf("(Y): %c | (X):%c\n",*Y[j+k],X[k]);

//                 if(Y[i][j] == X[k]) cnt ++;
//                 printf("index[%d] | (Y): %c == (X):%c\n",k,Y[j][k],X[k]);
//             }
//             printf(">[%d] %d\n",j,cnt);
//             if(cnt == (int)strlen(X)) num[i] ++;
//             // num[i] = cnt;
//         }
//         printf("index[%d] = %d\n",i,num[i]);
//         // X에 저장된 문자열이 가장 많이 나타나는 문자열을 찾기
        

//     }

//     //동적으로 할당 받은 메모리 해제
// }
// /*
// 정수 N을 입력받고, 공백을 포함하지 않는 문자열 한 개를 입력받아 정적 배열 X에 저 장한다. 

// 다음, N 줄의 공백을 포함하는 문자열을 입력받아, 
// 동적으로 저장 장소를 할당 받은 후 문자형 포인터 배열 Y에 연결한다. 
// Y의 데이터 타입은 char ** 이며, 포인터 배열도 동적으로 할당 을 받는다.

// 이 후, Y에 저장된 N 줄의 각 문자열에서 X에 저장된 문자열이 가장 많이 나타나는 문자열을 찾아 출력
// 단, 가장 많이 나타나는 문자열이 여러 개인 경우에는 가장 처음에 입력된 문자열을 출력한다.

// abcabc abcabc

// 3 abc
// abcabc abcabc
// ABCabc ABCabc 
// abc abc abc abcd
// */