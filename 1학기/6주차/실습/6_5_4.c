#include  <stdio.h>
int main() 
{
    int n,i,j;//3�� ������ ���� ����
    scanf("%d",&n);//���� �Է¹���
    for(i=n;i>0;i--){//�� �����ʹ� �ݴ��
        for(j=2*i-1;j>0;j--){//���� �Ʒ��� �� ���� ���� ���
            printf("*");
        }
        printf("\n");//������ ���
    }
    
}
