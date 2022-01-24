#include  <stdio.h>
int main(){
    char *pnum[3]={"Zero","One","Two"};
    for(int i=0;i<3;i++) printf("%s\n",pnum[i]);
    printf("-------\n");
    printf("%c",pnum[0][0]);


}