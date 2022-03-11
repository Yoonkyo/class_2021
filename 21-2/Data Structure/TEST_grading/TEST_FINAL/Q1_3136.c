#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node *prev;
    struct Node *next;
    char data;
}Node;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        Node *head=(Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->prev = NULL;
        Node* cur=head;
        char s[1000001];
        scanf("%s", s);
        for(int j=0; j<strlen(s); j++)
        {
            switch (s[j])
            {
                case '<': // 왼쪽으로 커서 이동
                {
                    if(cur->prev)
                        cur=cur->prev;
                    break;
                }
                case '>':  //오른쪽으로 커서 이동
                {
                    if(cur->next)
                        cur=cur->next;
                    break;
                }
                case '-':  //문자 삭제
                {
                    if(cur->prev==NULL)
                        continue;
                    Node* removed=(Node*)malloc(sizeof(Node));
                    removed=cur;
                    cur=removed->prev;
                    if(removed->next)
                    {
                        cur->next=removed->next;
                        removed->next->prev=cur;
                        removed->prev=NULL;
                    }
                    else
                        cur->next=NULL;
                    free(removed);
                    break;
                }
                case '!':  //문자 삭제
                {
                    head->next=NULL;
                    cur=head;
                    break;
                }
                default: 
                {
                    Node* newNode=(Node*)malloc(sizeof(Node));
                    newNode->data=s[j];
                    newNode->prev=cur;
                    if(cur->next)
                    {
                        newNode->next=cur->next;
                        cur->next->prev=newNode;
                    }
                    else
                    {
                        newNode->next=NULL;
                    }
                    cur->next=newNode;
                    cur=cur->next;
                    break;
                }
            }
        }
        head=head->next;
        while (head!=NULL)
        {
            printf("%c", head->data);
            head=head->next;
        }
        printf("\n");
        free(head);
    }
}