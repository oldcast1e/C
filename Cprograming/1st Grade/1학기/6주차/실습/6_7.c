#include<stdio.h>
int main(){

    int n;//������ ���� ����
    scanf("%d",&n);
    int a=1,b=n;//�ΰ��� ������ ��������

    for(int i=1;i<=n;i++){//��

        for(int j=1;j<=n;j++){//��
            if(j==a || j ==b){//X�� ��µǴ� ����
                printf("X ");
            }
            else    //�ƴ� ��� O���
                printf("O ");
            }
        a +=1;//X�� ��ġ ��ȭ
        b-=1;//X�� ��ġ ��ȭ
        printf("\n");//������ ���
    }
}

