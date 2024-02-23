#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
    char name[10];
    int score;
};
// void swap_name(char *a1,char a2){
//     struct student tmp;
// }


void swap(struct student *n,struct student *m){
    struct student *tmp;
    tmp.name = &n->name;
    // tmp.name = n->name; n->name = m->name; m->name = tmp.name;
    // tmp.score = n->score; n->score = m->score; m->score = tmp.score;
}

int main(){
    int n,rank;scanf("%d %d",&n,&rank);
    struct student cal[n];
    for(int i=0;i<n;i++){
        scanf("%s %d",cal[i].name,&cal[i].score);
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n-i-1;k++){
            if (cal[k].score > cal[k+1].score)
            {
                swap(&cal[k],&cal[k+1]);
                // printf(">ch");
                // swap_name(&cal[k].name,&cal[k+1].name);
                // swap(&cal[k].score,&cal[k+1].score);
            }
        }
    }
    for(int i=0;i<rank;i++)printf("%s\n",cal[i].name);

    
} 
/*

*/