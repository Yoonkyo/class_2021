#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char ele;
    struct Node *left;                              // Ʈ�� ����ü ����
    struct Node *right;
}Node;                                              
Node *NewNode(char ele)
{
    Node *New;
    New = (Node*)malloc(sizeof(Node));
    New->ele = ele;                                 // �� Ʈ�� ���� ���
    New->left = NULL;
    New->right= NULL;
    return New;
}                                                  
Node *search_Node(Node *H, char ele)
{
    if (H != NULL) {
        if (H->ele==ele) {
            return H;
        }
        else {
            Node *tmp = search_Node(H->left,ele);    // Ʈ�� Ž��
            if (tmp != NULL) {
                return tmp; 
            }
            
            return search_Node(H->right,ele);
        }
    }
    return NULL;
}                                                   
void insert_Node(Node *H,char A,char B,char C)
{
    H->ele = A;
    if (B != '.')
    {
        H->left = NewNode(B);                         // ��� �߰� �Լ� (A -> B -> C ������� ���, ����, ������)
    }
    if (C != '.')
    {
        H->right = NewNode(C);
    }
}
 
void print_pre(Node *H)
{
    if (H!=NULL)
        printf("%c", H->ele);
    if (H->left!=NULL)
    print_pre(H->left);                               // ���� ��ȸ �Լ�
    if (H->right != NULL)
    print_pre(H->right);
}
void print_in(Node *H)
{
    if (H->left!=NULL)
    print_in(H->left);
    if (H != NULL)                                    // ���� ��ȸ �Լ�
        printf("%c", H->ele);
    if (H->right!=NULL)
    print_in(H->right);
}
void print_post(Node *H)
{
    if (H->left != NULL)
    print_post(H->left);
    if (H->right != NULL)                              // ���� ��ȸ �Լ�
    print_post(H->right);
    if (H != NULL)
        printf("%c", H->ele);
}
 
 
int main()
{
    Node *H = NewNode(NULL);                          // ����ִ� �⺻�� Ʈ�� ����
    Node *tmp;                                        
    int N;                                            // ����� ����
    int i;                                            
    scanf("%d", &N);                                  // ����� ���� �Է¹ޱ�
    getchar();                                        // ����� ����(N)�� �Է¹ް� \n�� ���ۿ��� ���ֱ� ����
    for (i = 0;i < N;i++)
    {
        char A, B, C;                                 // �� ���(A)�� ���� ���� �ڽ� ���(B), ������ �ڽ� ���(C)
        scanf("%c %c %c", &A, &B, &C);                // �� ���(A)�� ���� ���� �ڽ� ���(B), ������ �ڽ� ���(C) �Է¹ޱ�
        getchar();                                    // \n�� ���ۿ��� ���ֱ� ����
        tmp = search_Node(H, A);                      // A�� ����� ��� ã��
        if (tmp != NULL)                              // �ʱ� Ʈ�� ����
            insert_Node(tmp, A, B, C);                // searchnode ���� Ʈ�� �߰�
        else                                          // ���� ù ���� ���, �ʱ� Ʈ�� ����
        insert_Node(H,A,B,C);                         // ���� NULL�� �⺻�� Ʈ���� A,B,C ����
    }
    print_pre(H);                                     // ���� ��ȸ
    printf("\n");
    print_in(H);                                      // ���� ��ȸ
    printf("\n");
    print_post(H);                                    // ���� ��ȸ
}
