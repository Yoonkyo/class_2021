#include <stdio.h>
#include <string.h>

int main(void){
    char L[600000],R[300010],temp;//Ŀ���� �����ʰ� ���ʿ� �ű迡 ���� Ȱ���� ���� L,R ����
    int left,right,N;
    scanf("%s",L);
    left=strlen(L),right=300000;//L,R�� ���� ������
    scanf("%d",&N);
    while(N--){
        scanf("\n%c",&temp);
        if(temp=='L'&&left!=0){//L�� �Էµǰ� L�� �����Ͱ� 0�� �ƴϸ�
            R[right--]=L[--left];//L�� ������ ���ڸ� R�� ������ ���� �ڸ��� �Է��ϰ� L�� ������ ����
            L[left]='\0'; 
        }
        else if(temp=='D'&&right!=300000){//D�� �Էµǰ� R�� �����Ͱ� ���������Ͱ� �ƴϸ�
            L[left++]=R[++right];//R�� ������ ������ ���ڸ� L�� ������ ��ġ�� �Է�
            R[right]='\0';
        }
        else if(temp=='B'&&left!=0){//B�� �Էµǰ� L�� �����Ͱ� 0�� �ƴϸ�
            L[--left]='\0';//L�� ������ ���� ��������
        }
        else if(temp=='P'){
            scanf("\n%c",&temp);
            L[left++]=temp;//P�� �ԷµǸ� ���ڸ� �Է¹ް� L�� �� �����Ϳ� ����
        }
    }
    printf("%s%s",L,&R[right+1]);//���ڿ� L��R�� �̾� ��� R�� ���� �����ʹ� �����̹Ƿ� �����ʺ��� ���

}