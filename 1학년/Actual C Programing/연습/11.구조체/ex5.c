#include  <stdio.h>
struct student4{
    /* data */
    int id; char *pname; double grade;
};

int main(){
    struct student4 st;
    st.pname = "Mary";

    printf("%p\n",&st.pname);
    printf("%s",st.pname);


}