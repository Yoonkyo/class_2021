#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char ele;
    struct Node *left;                              // 트리 구조체 형성
    struct Node *right;
}Node;                                              
Node *NewNode(char ele)
{
    Node *New;
    New = (Node*)malloc(sizeof(Node));
    New->ele = ele;                                 // 빈 트리 구조 등록
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
            Node *tmp = search_Node(H->left,ele);    // 트리 탐색
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
        H->left = NewNode(B);                         // 노드 추가 함수 (A -> B -> C 순서대로 헤드, 왼쪽, 오른쪽)
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
    print_pre(H->left);                               // 전위 순회 함수
    if (H->right != NULL)
    print_pre(H->right);
}
void print_in(Node *H)
{
    if (H->left!=NULL)
    print_in(H->left);
    if (H != NULL)                                    // 중위 순회 함수
        printf("%c", H->ele);
    if (H->right!=NULL)
    print_in(H->right);
}
void print_post(Node *H)
{
    if (H->left != NULL)
    print_post(H->left);
    if (H->right != NULL)                              // 후위 순회 함수
    print_post(H->right);
    if (H != NULL)
        printf("%c", H->ele);
}
 
 
int main()
{
    Node *H = NewNode(NULL);                          // 비어있는 기본형 트리 형성
    Node *tmp;                                        
    int N;                                            // 노드의 개수
    int i;                                            
    scanf("%d", &N);                                  // 노드의 개수 입력받기
    getchar();                                        // 노드의 개수(N)만 입력받고 \n를 버퍼에서 없애기 위해
    for (i = 0;i < N;i++)
    {
        char A, B, C;                                 // 각 노드(A)와 그의 왼쪽 자식 노드(B), 오른쪽 자식 노드(C)
        scanf("%c %c %c", &A, &B, &C);                // 각 노드(A)와 그의 왼쪽 자식 노드(B), 오른쪽 자식 노드(C) 입력받기
        getchar();                                    // \n를 버퍼에서 없애기 위해
        tmp = search_Node(H, A);                      // A가 저장될 장소 찾기
        if (tmp != NULL)                              // 초기 트리 이후
            insert_Node(tmp, A, B, C);                // searchnode 이후 트리 추가
        else                                          // 가장 첫 번쨰 경우, 초기 트리 설정
        insert_Node(H,A,B,C);                         // 전부 NULL인 기본형 트리에 A,B,C 대입
    }
    print_pre(H);                                     // 전위 순회
    printf("\n");
    print_in(H);                                      // 중위 순회
    printf("\n");
    print_post(H);                                    // 후위 순회
}
