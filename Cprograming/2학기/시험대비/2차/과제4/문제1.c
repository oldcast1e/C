#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct st{
    char *str; // 문자열 저장 
    int cnt1; // 자음 수 저장 
    int cnt2; // 모음 수 저장
};

int main(){

    int N;
    scanf("%d",&N);getchar();
    struct st *sys = NULL;
    sys = (struct st *)malloc(sizeof(struct st)*N);
    if(sys == NULL){
        printf("Error");
        return -1;
    }
    // 같은 구조체를 정의해서 사용하고, 구조체 배열과 문자열을 저장 할 배열은 동적으로 할당 받아 사용
    char str[100];
    for(int i=0;i<N;i++){
        gets(str);
        int len  = strlen(str);
        sys[i].cnt1 = 0;sys[i].cnt2 = 0;

        sys[i].str = (char*)malloc(sizeof(char)*len+1);
        if(sys[i].str == NULL){
            printf("Error");
            return -1;
        }
        strcpy(sys[i].str,str);
        for(int j=0;j<len;j++){
            if('a' == sys[i].str[j]|| 'e' == sys[i].str[j] || 'i' == sys[i].str[j] || 'o' == sys[i].str[j]  || 'u' == sys[i].str[j])
                sys[i].cnt2 ++;
            if('A' == sys[i].str[j]|| 'E' == sys[i].str[j] || 'I' == sys[i].str[j] || 'O' == sys[i].str[j]  || 'U' == sys[i].str[j])
                sys[i].cnt2 ++;
            else sys[i].cnt1 ++;
        }
        // 문자열을 저장 할 배열의 크기는 문자개수+1 (위반 시 30% 감점)
        // 각 문자열에 포함된 자음의 수와 모음의 수를 세어
    }
    // 자음의 수가 가장 많은 문자열부터 내림 차순으로 정렬 한 후 순서대로 문자열을 출력
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            if(sys[j].cnt1 < sys[j+1].cnt1){
                struct st tmp;
                tmp = sys[j];
                sys[j] = sys[j+1];
                sys[j+1] = tmp;
                //자음의 수가 가장 많은 문자열부터 내림 차순으로 정렬
                //자음의 수가 같은 문자열에 대해서는 모 음의 수가 가장 많은 문자열부터 출력
                //자음의 수와 모음의 수가 같은 문자열이 있는 경우에는 입력된 순서대로 출력 하시오
            }
            else if(sys[j].cnt1 == sys[j+1].cnt1){
                if(sys[j].cnt2 < sys[j+1].cnt2){
                    struct st tmp;
                    tmp = sys[j];
                    sys[j] = sys[j+1];
                    sys[j+1] = tmp;
                }
            }
        }
    }
    for(int i=0;i<N;i++) printf("%s\n",sys[i].str);


}
/*
5
History
Politics
DonQuixote
LaPeste
Chaos
*/