#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct customer{ 
    char id[5];
    char *name;
    char *phone; 
};

void reset(char *str){
    for(int i=0;i<100;i++)str[i] = '\0';
}
int main(){

    int N,len,space,cnt = 0;
    char str[100];
    char str_name[100],str_phn[100];
    char separator[] = "' ','\n'";

    char input[5];
    
    scanf("%d",&N); getchar();
    
    struct customer *system = NULL;
    system = (struct customer *)malloc(N*sizeof(struct customer));
    //고객 수 N을 입력받고, 크기 N의 구조체 배열을 동적으로 할당 받아, 고객 정보를 저장한다.
    for(int i=0;i<N;i++){
        // reset(str_name);reset(str_phn);
        gets(str);len = strlen(str);

        cnt = 0;

        char *token = strtok(str,separator);
        while(token != NULL){
            if(cnt == 0){
                strcpy(str_name,token);
                cnt ++;
                // printf("str_name: %s\n",token);
            }
            else if(cnt == 1) {
                strcpy(str_phn,token);
                // printf("str_phn: %s\n",token);
            }
            token = strtok(NULL,separator);
        }

        system[i].name = (char*)malloc((int)strlen(str_name)*sizeof(char));
        system[i].phone = (char*)malloc((int)strlen(str_phn)*sizeof(char));
        strcpy(system[i].name,str_name);
        strcpy(system[i].phone,str_phn);    

        cnt = 0;
        for(int j=9;j<13;j++){
            system[i].id[cnt] = system[i].phone[j];
            cnt ++;
        }
        // strcpy(system[i].phone,str_phn); strcat(system[i].phone,"\0");
    }
    scanf("%s",input);

    for(int i=0;i<N;i++){
        if(strcmp(input,system[i].id)==0){
            printf("%s %s %d",system[i].name,system[i].phone,i+1);
        }
    }


}
/*
KimSooJin 010-1234-5678
ParkGilDong 010-2468-1357
ChungSangChul 010-1230-4567
LeeYoungHee 010-1357-2468
ChoiMyungHee 010-3458-1267

*/