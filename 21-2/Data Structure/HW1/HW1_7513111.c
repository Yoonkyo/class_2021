#include <stdio.h>
#include <string.h> //strlen �Լ��� ���� ���� ��������Դϴ�

int main(){
    int T;  //�����͸� T�� �޾Ƽ� ������ ���� �Ǵ��ϴ� �����Դϴ�
    char PS[50];  //���ڿ��� ���̴� 50 ����
    scanf("%d", &T); //T�� �Է¹ޱ�

    for(int i=0; i<T; i++){  //T�� �����ϴ� �ݺ���
        scanf("%s", PS);  //T�� ������ ���� ���ڿ��� �Է¹޽��ϴ�
        int count=0;  //count�� ���� 0���� �ʱ�ȭ�մϴ�

        for(int j=0; j<strlen(PS); j++){  //strlen �Լ��� ���ڿ��� ���̸� ���, �� ���̸�ŭ �ݺ�
            if (PS[j]=='(')  
                count++;
            else if (PS[j]==')')
                count--;  //�ݺ����� ������ count�� ���� 0�̸� YES
            if (count<0)
                break;  //count�� ���� 0�̶�, ���� ��� "))(("�� NO��� �Ǻ��ؾ� �մϴ�
        }
        if (count==0)
            printf("YES\n");
        else    
            printf("NO\n"); //count ���� ���� YES, NO�� ���
    }
    return 0;
}