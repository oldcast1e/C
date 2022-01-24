#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    char book;//예약할 경우(y), 예약하지 않을 경우(n), 예약을 변경할 경우(c)
    char room;//펜트하우스(p), 스위트룸(s), 디럭스룸(d)
    int romcode;//객실유형별 방 번호 (숫자입력) - 펜트하우스(1), 스위트룸(1,2,3), 디럭스룸(1,2,3,4,5,6)
    char name [10];// 예약자명 (띄어쓰기포함 20자리이내 입력): 영문 영어이름

    char hotel[10][10]= {0};int key = 0 ;
    for(int i=0;i<10;i++) strcpy(hotel[i],"0\0");
    while (1){
        scanf("%c %c %d %s",&book,&room,&romcode,name);
        getchar();
        key = 0;
        if(book == 'n')break;
        else if(book == 'y'){
            if(room == 'p'){
                if(strcmp(hotel[0],"0")==0){
                // printf("><");
                    strcpy(hotel[0],name);
                }
                else{
                     printf("please select another room");
                     key = 1;
                }
            }
            else if(room == 's'){
                if(strcmp(hotel[romcode],"0")==0){
                // printf("><");
                    strcpy(hotel[romcode],name);
                }
                else{
                     printf("please select another room");
                     key = 1;
                }
            }

            else if(room == 'd'){
                if(strcmp(hotel[romcode+3],"0")==0){
                // printf("><");
                    strcpy(hotel[romcode+3],name);
                }
                else{
                     printf("please select another room");
                     key = 1;
                }
            }
            if(key == 0){
                for(int i=0;i<10;i++) printf("%s ",hotel[i]);
            }
            printf("\n");
        }
        else if(book == 'c'){

        }
        
    }
    
}

/*


4) 예약자명 (띄어쓰기포함 20자리이내 입력): 영문 영어이름

입력을 받은 후 현재의 객실예약상태를 출력 (예약되지 않은 방은 0, 예약된 방은 예약자명을 출 력) 한다. 

만약 예약을 변경할 경우에는 입력된 내용으로 새로운 객실예약이 진행되고,
해당 이름 으로 예약된 기존예약정보는 삭제된다.
다음 조건을 고려하여 해당 객실의 위치에 예약자명을 아 래 입 출력 예시와 같이 출력하시오.

- (조건 1) 객실의 수는 총 10개이며, 출력은 좌측부터 펜트하우스 1, 스위트룸 1~3, 디럭스룸 1~6 이다.
- (조건 2) 신규예약 및 예약수정 시 이미 예약된 방을 예약하려 할 경우 please select another room 을 출력한다.
- (조건 3) 객실예약 여부의 입력이 n 일 때까지 반복하여 예약을 받는다.
- (조건 4) 최초 객실은 모두 비었다고 가정한다.
- (조건 5) 올바르지 않은 값이 입력될 경우 please input correctly를 출력한다. 올바르지 않은 값은 아래와 같이 정의한다.

i)예약여부에허용된입력값(y,n,c)이외의한자리영문대소문자가입력될 경우 
ii)방종류에허용된입력값(p,s,d)이외의한자리영문대소문자가입력될경 우 
iii) 객실유형별 방 번호에 허용된 입력값
 (펜트하우스 1; 스위트룸: 1,2,3; 디럭스룸:1,2,3,4,5,6) 이외의 수가 입력될 경우)

- (조건 6) 빈 객실 예약 시, 예약자명과 기예약된 다른 객실의 예약자명이 같을 경우 please input another name을 출력한다.
- (조건 7) 예약수정 시, 예약하려는 객실이 비어있고 기존에 예약정보(이름)가 없다면 수정 없이 해당 객실에 예약됨.

*/