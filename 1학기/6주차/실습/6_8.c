#include<stdio.h>
int main(){
    
    int n,m,cnt=0,cnt2=1;//������ ���� 4�� ����
    scanf("%d",&n);//n�Է� ����
    m = n;//���� m�� n�� ����_�Ⱦ�
    

    while(cnt2<=n){//cnt2�� n���� �۰ų� ���� ���

        for(int j=1;j<=10;j++){//��
            
            if(cnt2>n)//cnt2�� n���� ũ�� ����
                break;

            if(j==10)//j==10�̸� 10���� 0���
                printf("%d",0);
            else//�������� j���
                printf("%d",j);
            cnt +=1;
            if(cnt%n==0){//������ �� ��ŭ ����ϰ� ���� �ٲٴ� �ڵ�
                cnt2 +=1;
                if(cnt2<=n)//cnt2�� n���� �۰ų� ������
                    printf("\n");//�� �ٲ�
            }
            // printf("\ncnt2 : %d\n",cnt2);
        }
        

    }

    
}

