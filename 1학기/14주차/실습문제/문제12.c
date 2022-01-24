#include  <stdio.h>

void addArray(int **p1,int **p2,int **p3,int N){//addArray함수 

    int *pp1 = *p1,*pp2 = *p2,*pp3 = *p3;
    for(int i=0;i<N;i++){
        *(pp3+i) = *(pp1+i) + *(pp2+i);
        // printf("%d ",*(p1+i));
    }
}

int main(){//메인 함수 선언
   
    int N;
    int A[20],B[20],R[20];
    int *p1 = A,*p2 = B,*p3 = R;
    scanf("%d",&N);

    for(p1=A;p1<A+N;p1++){
        scanf("%d",p1);
    }
    for(p2=B;p2<B+N;p2++){
        scanf("%d",p2);
    }
    addArray(&p1,&p2,&p3,N);

    for(p3=R;p3<R+N;p3++){
        printf(" %d",*p3);
    }




    

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

