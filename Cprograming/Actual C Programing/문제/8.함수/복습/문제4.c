#include  <stdio.h>
void print_row1(int n){
    for(int i=0;i<n;i++) printf("%d",n);
}
void print_row2(int n){
    for(int i=0;i<n;i++){
        if(i==0 || i ==n-1) printf("%d",n);
        else printf(" ");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i==0 || i ==n-1){
            print_row1(n);
            printf("\n");
        } 
        else{
            print_row2(n);
            printf("\n");
        }
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

