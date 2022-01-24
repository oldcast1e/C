#include  <stdio.h>

struct
{
    /* data */
    char id[30];
}st = {"Heosneong"};

int main(){

    st.id[1] = 'd';
    printf("%s",st.id);
}