#include<stdio.h>
int main(){

    int N,M,min,cnt;//N,M���� ���� ����
    scanf("%d %d",&N,&M);//�� ���� ���� �Է¹���
    min = (N>M?M:N);//�������� �ּڰ� ã��
    cnt = min; //cnt�� ����
    while(min>0){//�ּڰ��� 0���� ū ��� �ݺ�

        if(N%cnt==0 && M%cnt==0){//N,M�� �ִ����� ã��
            printf("%d",cnt);//ã���� ����
            break;
        }
        cnt-=1;//
        min -=1;//�κ����� ���� �����ϰ� -1��
    }
    
}