#include <stdio.h>
#include <stdlib.h>

//연결 리스트를 사용해 Node 만들기
typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
} Node;

//Node에 data 입력
Node *MakeNode(int data)
{
    Node *nd = (Node *)malloc(sizeof(Node));

    nd->data = data;
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

//이진트리의 특징을 이용한 트리 만들기
Node *MakeTree(Node *bt, int data)
{
    if (bt == NULL)
    {
        bt = MakeNode(data);
    }

    else if (bt->data > data)
    {
        bt->left = MakeTree(bt->left, data);
    }

    else if (bt->data < data)
    {
        bt->right = MakeTree(bt->right, data);
    }

    return bt;
}

//후위순위 구현
void PostOrder(Node *bt)
{
    if (bt == NULL)
        return;
    PostOrder(bt->left);
    PostOrder(bt->right);
    printf("%d\n", bt->data);
}

int main()
{
    int n;
    Node *bt = NULL;
    while (scanf("%d", &n) != EOF)//EOF를 받기전까지 입력값을 받는다
    {
        bt = MakeTree(bt , n);
    }

    PostOrder(bt);
    
    return 0;
}
