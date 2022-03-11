#include <stdio.h>
#define SIZE 100  //�ǿ������� �ִ� ����

char stack[SIZE],temp;  // ������ ���� �迭
int top = -1;   // �� ���� ���Ҹ� ��Ÿ�� top����

int isFull() {    // ������ ��ȭ �������� �˻��ϴ� �Լ�
	if(top >= SIZE - 1) {   // top�� �ִ� ũ��� ���ų� Ŭ ���
		printf("Error : Stack is Full. \n");  // �����޽��� ���
		return 1;  // 1 ��ȯ (true)
	}
	return 0;   // �׷��� ���� ��� 0 ��ȯ (false)
}

int isEmpty() {    // ������ ���� �������� �˻��ϴ� �Լ�
	if(top == -1) {    // top�� -1�� ���
		printf("Error : Stack is empty. \n");  // �����޽��� ���
		return 1;  // 1 ��ȯ (true)
	}
	return 0;   // �׷��� ���� ��� 0 ��ȯ (false)
}

void push(double data) {      // ���ÿ� ���Ҹ� �����ϴ� �Լ�
	if(!isFull()) {    // ������ ��ȭ ���°� �ƴ� ���
		top++;         // top�� 1 ����
		stack[top] = data;   // �ش� ������ data ����
	}
}
 
double pop() {  // ���ÿ� ���Ҹ� �����ϴ� �Լ�
	if(!isEmpty())  {   // �迭�� ������� ���� ���
		char temp = stack[top];    // top ���Ҹ� �ӽ� ���� temp�� ����
		top--;                     // top ���� 1 ����
		return temp;               // temp ��ȯ
	}
}
int main()
{
    int m=0,n,i,j; // �ǿ������� ������ ���� ����
    char c[100]; // �ǿ����ڿ� �ش��ϴ� ���� ���� �迭; // �ǿ����� ���� �ޱ�
    char s[100];
    scanf("%d",&n); // ���� ǥ����� ���� �迭
     // ���� ǥ��� �ޱ�
    for(int k = 0; k<n; k++){ 
        scanf("%s\n", &c[k]);// ������ ���� ������ �ݺ�
        char b = c[k]; // ���� ǥ��� ���� ������ �ڸ���
        if(b <= 'Z' && b >= 'A'){
            s[m]=c[k];
            m=m+1;
        }
        else if(b=='*' || b=='+' || b=='-' || b=='/' || b=='('){
            push(c[k]);
        }
        else if ( b==')'){
            for(i=0; i<top;i++){
                s[m]=temp;
                pop();
            }
        }
        else{
            break;
        }
    }
    for(j=0;j<=m;j++){
        printf("%s",s[j]);
    } // ���ĺ��� ��� �з�
    return 0;
}