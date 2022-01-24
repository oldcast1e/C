#include  <stdio.h>
#include  <string.h>
struct student{
    /* data */
    char subject[50];
    char sn[9];
};

int main(){
    int N;
    struct student st[100];
    scanf("%d",&N);
    getchar();

    for(int i=0;i<N;i++){
        gets(st[i].subject);
        gets(st[i].sn);
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i!=j){
                // printf("(%s | %s)\n",st[i].subject,st[j].subject);
                if(strcmp(st[i].subject,st[j].subject)>0){
                    // printf("<%s | %s>\n",st[i].subject, st[j].subject);
                    struct student tmp = st[i];
                    st[i] =  st[j];
                    st[j] = tmp;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i!=j){
                // printf("(%s | %s)\n",st[i].subject,st[j].subject);
                if(strcmp(st[i].subject,st[j].subject)==0){
                    
                    if(strcmp(st[i].sn,st[j].sn)>0){
                        
                        struct student tmp = st[i];
                        st[i] =  st[j];
                        st[j] = tmp;
                    }
                }
            }
        }
    }
    // printf("\n----------------\n");


    for(int i=0;i<N;i++){
        puts(st[i].subject);
        puts(st[i].sn);
    }


}

/*
5
computer engineering 
1712745
biology
1720824
computer engineering 
1760432
biology
1712345
computer engineering 
1713812

*/