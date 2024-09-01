#include <stdio.h>
#include <string.h>
struct student {//구조체 정의
   int id;
   char *pname;
};

int main(){
    struct student st;
    struct student *pst;
    st.id = 21011898;
    st.pname = "Marry";

    printf("id : %d\n",st.id);
    printf("name : %c\n",*st.pname);

    pst = &st;
    printf("p_id : %d\n",(*pst).id);
    printf("P_name : %s\n",pst->pname);
    // printf("grade : %.2f\n",st[0].grade);
}