#include <stdio.h>
#include <string.h>
struct student {//구조체 정의
   int id;
   char name[8];
};

void init_v(struct student st){
    st.id = 0;
    strcpy(st.name," ");
}

void init_p(struct student *pst){
    pst->id = 0;
    strcpy(pst->name," ");
}

int main(){
    struct student st = {21011898,"Lee"};
    init_v(st);
    printf("값 전달 후: %d , %s\n",st.id,st.name);
    init_p(&st);
    printf("값 전달 후: %d , %s",st.id,st.name);


}