#include <stdio.h>
#include <string.h>
#include <ctype.h>//���ڼ��� �Ǻ� ���

int main(void){
    int T,left,check,right;
    scanf("%d",&T);
    while(T--){
        char S[1000001]={0},L[1000001]={0},R[1000001]={0};//�Է¹��� ���ڿ�, '>'��'<'���� L��R �迭�� ����ó��
        scanf("%s",S);
        check=strlen(S);
        left=-1,right=1000000;//������ �ʱ� ������ 
        for(int i=0;i<check;i++){//�Է¹��� ���ڿ� �ϳ��� �Ǻ�
            if(S[i]=='-'&&left!=-1){//'-'��� L���� ���� �ϳ� �����
                L[left]='\0';
                left--;
            }
            else if(S[i]=='<'&&left!=-1){//'<'��� L�� ���� ������ ���ڸ� R�� ���� �������� �ű�� 
                R[--right]=L[left];
                L[left--]='\0';
            }
            else if(S[i]=='>'&&right!=1000000){//'>'��� R�� ���� ���� ���ڸ� L�� ���� ���������� �ű��
                L[++left]=R[right++];
                R[right-1]='\0';
            }
            else if(isalpha(S[i])||isdigit(S[i])){//���ڳ� ���ڶ�� ���ڿ��� �߰�
                L[++left]=S[i];
            }
        }
        printf("%s%s\n",L,&R[right]);//L�� R�� ����� ���ڿ� �̾���̱�
    }
    return 0;
}