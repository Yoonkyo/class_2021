#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char arr[1000001];
int i = 0;
 
typedef struct _Node
{
    char s;
    struct _Node *next;
    struct _Node *prev;
}Node;
 
typedef struct _List
{
    Node *first;
    Node *last;
    Node *cur;
}List;
 
void init(List *list)
{
    Node *newnodeF = (Node*)malloc(sizeof(Node)); // 앞쪽 더미 노드
    Node *newnodeL = (Node*)malloc(sizeof(Node)); // 뒤쪽 더미 노드
 
    newnodeF->next = newnodeL;
    newnodeF->prev = NULL;
    newnodeF->s = NULL;
 
    newnodeL->next = NULL;
    newnodeL->prev = newnodeF;
    newnodeF->s = NULL;
 
    list->first = newnodeF;
    list->last = newnodeL;
    list->cur = newnodeF;
}

void next(List *list)
{
    /* '<' 를 받으면
     * 왼쪽으로 한칸 옮기기 전, 아무것도 없는지 혹은 문자가 있는 첫 노드인지 확인한다.  
     * 이동 방식은 현재 위치를 가리키는 cur을 왼쪽으로 한칸 옮긴다.
     */
    if (arr[i] == '<')
    {
        if (list->cur->prev != list->first || list->cur == list->first->next)
        {
            if (list->cur != list->first)
                list->cur = list->cur->prev;
        }
    }
 
    /* '>' 를 받으면
    * 오른쪽으로 한칸 옮기기 전, 아무것도 없는지 혹은 문자가 있는 마지막 노드인지 확인한다.
    * 이동 방식은 현재 위치를 가리키는 cur을 오른쪽으로 한칸 옮긴다.
    */
    else if (arr[i] == '>')
    {
        if (list->cur->next != list->last)
        {
            if (list->cur != list->last)
                list->cur = list->cur->next;
        }
    }
 
    /* '-' 를 받으면
    * cur에 해당하는 노드를 삭제한다. 이때 삭제하기전, cur에 대한 정보가 필요하므로
    * 삭제할 노드는 tmp에 담아 삭제한다.
    * 삭제 방식은 지우는 노드의 좌 우 노드를 연결 한 후 삭제해야한다.
    */
    else if (arr[i] == '-')
    {
        if (list->cur->s != NULL)
        {
            Node *tmp = list->cur;
 
            // 지우는 노드의 양 좌 우 노드를 연결해준다.
            list->cur->next->prev = list->cur->prev;
            list->cur->prev->next = list->cur->next;
 
            list->cur = list->cur->prev;
            free(tmp);
        }
    }
    else if (arr[i] == '!'){
        list = NULL;

    }
 
    /* 그 외에 문자를 받으면 노드를 생성하여 이어준다.
    * 잇는 방식은 newnode를 먼저 이어주고 난 뒤,
    * 기존에 존재하던 노드를 이어준다.
    */
    else
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
 
        newnode->prev = list->cur;
        newnode->next = list->cur->next;
 
        newnode->s = arr[i];
 
        list->cur->next->prev = newnode;
        list->cur->next = newnode;
        list->cur = newnode;
    }
    i++;
}
 
void print(List *list)
{
    // 처음부터 끝까지 출력을 한다.
    list->cur = list->first->next;
 
    while (list->cur != list->last)
    {
        printf("%c", list->cur->s);
        list->cur = list->cur->next;
    }
    printf("\n");
 
    // 출력 후 free를 통해 다음 테스트 케이스를 받을 준비를 한다.
    list->cur = list->first;
 
    while (list->cur != list->last)
    {
        Node *tmp = list->cur;
 
        list->cur = list->cur->next;
        free(tmp);
    }
    free(list->last);
    i = 0; // i 초기화(배열 번호에 이용)
}
 
 
int main()
{
    int len;
    int n;
 
    scanf("%d", &n); // 테스트 케이스의 개수 입력받기
 
    for (int i = 0; i < n; i++)
    {
        List list;
        scanf("%s", arr);
 
        len = strlen(arr);

        init(&list); // 더미 노드를 만들어 첫 노드와 끝 노드의 삽입 삭제를 편리하게 한다.
 
        for (int i = 0; i < len; i++)
            next(&list);
 
        print(&list);
 
    }
 
    return 0;
}