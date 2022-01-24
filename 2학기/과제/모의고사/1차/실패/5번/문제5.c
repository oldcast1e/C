#include  <stdio.h>
#include  <string.h>
struct studendt{
    /* data */
    char subject[50];
    int sn;
};

int main(){
    int N;
    struct studendt st[100];
    scanf("%d",&N);
    getchar();

    for(int i=0;i<N;i++){
        gets(st[i].subject);
        scanf("%d",&st[i].sn);
        getchar();
        
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i!=j){
                if(strcpy(st[i].subject,st[j].subject)>0){
                    struct studendt tmp = st[i];
                    printf(">>> %s %d\n",tmp.subject,tmp.sn);
                    st[i] = st[j];
                    st[j] = tmp;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        printf("%s %d\n",st[i].subject,st[i].sn);
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