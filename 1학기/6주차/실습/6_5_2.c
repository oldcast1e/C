#include  <stdio.h>
int main() 
{
    int n,i,j;//3���� ������ ���� ����
    scanf("%d",&n);//���� �Է¹���
    for(i=n;i>0;i--){//n���� 1����
        for(j=i;j>0;j--){//��(������ �۾���)
            printf("*");
        }
        printf("\n");//������ ���
    }
    
}
