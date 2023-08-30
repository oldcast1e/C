#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct customer{ char id[5];
    char *name;
    char *phone; 
};

void reset(char *str){
    for(int i=0;i<100;i++)str[i] = '\0';
}
int main(){

    int N,len,space,cnt = 0;
    int namelen;
    char str[100];
    char str_name[100],str_phn[100];
    scanf("%d",&N); getchar();
    struct customer *system = NULL;
    system = (struct customer*)malloc(N*sizeof(struct customer));
    //고객 수 N을 입력받고, 크기 N의 구조체 배열을 동적으로 할당 받아, 고객 정보를 저장한다.
    for(int i=0;i<N;i++){
        reset(str_name);reset(str_phn);
        
        gets(str);len = strlen(str);

        space = 0;
        for(int j=0;j<len;j++){
            if(str[j]==' '){
                space++;
                cnt=0;
            }

            if(space == 0 && str[j]!=' ' ){
                str_name[cnt] = str[j];
                cnt ++;
            }
            else if(space == 1 && str[j]!=' ' ){
                str_phn[cnt] = str[j];
                cnt ++;
            }
        }
        strcat(str_name,"\0");strcat(str_phn,"\0");
        
        // printf("%s\n",str_name);
        namelen = strlen(str_name);
        system[i].name = (char*)malloc(namelen*sizeof(char));
        strcpy(system[i].name,str_name); strcat(system[i].name,"\0");

        // strcpy(system[i].phone,str_phn); strcat(system[i].phone,"\0");
    }
    for(int i=0;i<N;i++)printf("%s\n",system[i].name);


}
/*
KimSooJin 010-1234-5678
ParkGilDong 010-2468-1357
ChungSangChul 010-1230-4567
LeeYoungHee 010-1357-2468
ChoiMyungHee 010-3458-1267

*/