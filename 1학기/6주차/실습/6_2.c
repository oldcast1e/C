#include  <stdio.h>
int main() 
{
    int n,sum=0;//������ �� ���� ����
    scanf("%d",&n);//���� �Է¹���
    
    while(n!=0){//n�� 0�� �ƴѰ�� �ݺ�
        sum +=n;//�� ������ n����
        scanf("%d",&n);//n�Է¹���
        if(n==0)//n�� 0�϶� �ݺ��� ����
            break;
    }
    printf("%d",sum);//�� ���
    


}
