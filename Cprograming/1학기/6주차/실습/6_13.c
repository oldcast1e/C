#include<stdio.h>
int main(){
    
    int n,m,rst;//�Է¹��� ��
    int num=1,cnt=0;
 
    scanf("%d",&n);//n�� ���� �Է¹���
    while(num<=n){

        if(num>10){//10�� �ڸ� �̻��� ���
            m = num;
            while(m>0){//n�� ����϶� �ݺ�
                rst = m%10;//n�� ������ ����=3���ִ��� Ȯ��
                if(rst==3)
                    cnt ++;//3�� ��� ī��Ʈ�� 1�ø�
                m /=10;//n�� �ڸ����� ����
             }
        }
        else{//1�� �ڸ��ΰ��
            if(num==3)//3�� ���
                cnt +=1;//ī��Ʈ�� �ø�
        }
        num++;//�ݺ� ����
    }
    printf("%d",cnt);//3�� ���� Ƚ�� ���
}