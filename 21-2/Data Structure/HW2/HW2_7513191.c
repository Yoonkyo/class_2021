  
#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList{
    char data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //이제 LinkedList은 노드로 대체할 수 있습니다.
node CreateNode(char value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList));  // Malloc()에 대한 메모리 영역 발급loc()
    temp->next = NULL;// NULL에 next을 가리킵니다.
    temp->data = value; // 노드에 값 할당
    return temp;//이미 값이 있는 새 node 반환
}
 // 끝자리에 추가하다
node AddTail(node head, char value){
    node temp,p;/// 임시 temp 및 p 노드 2개 신고
    temp = CreateNode(value);//createNode 함수를 호출하여 NULL을 가리키고 값이 value인 temp 노드를 초기화합니다.rỏ tới NULL và giá trị là value
    if(head == NULL){
        head = temp;      // linked list이 비어 있으면 노드 temp가 head입니다
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;//링크 목록을 끝까지 스크롤합니다. 끝 노드는 next = NULL이 있는 노드입니다.
        }
        p->next = temp;
    }
    return head;
}
  // 앞자리에 추가하다

node AddHead(node head, char value){
    node temp = CreateNode(value); // Khởi tạo node temp với data = value
    if(head == NULL){
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }else{
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}
 //임의의 위치에 추가 

node AddAt(node head, char value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); // 삽입 위치가 0이면 head에 추가합니다.
    }else{
        // 삽입할 위치 찾기를 시작합니다. k를 이용해서 위치를 세겠습니다
        int k = 0;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k <= position){
            // 목록을 다 스크롤했는데 아직 삽입할 위치에 도달하지 않은 경우 마지막 삽입을 기본값으로 합니다.
            head = AddTail(head, value);
        }else{
            node temp = CreateNode(value);// node temp를 초기화하고 node temp의 value에 
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 //앞자리에 삭제
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
  // 끝자리 삭제
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; 
    return head;
}
  // 임의의 위치에 삭제
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head); // 삽입 위치가 0이면 head에 추가합니다.
    }else{
        // 삽입할 위치 찾기를 시작합니다. k를 이용해서 위치를 세겠습니다.
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            //  목록을 다 스크롤했는데 아직 삽입할 위치에 도달하지 않았다면, 마지막을 삭제하려고 합니다.
            head = DelTail(head);
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
//노드가 들어 있는 목록 인쇄
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5c", p->data);
    }
}
 
node InitHead(){
    node head;
    head = NULL;
    return head;
}
 
node Input(){
    node head = InitHead();
    int n;
    char value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf(" %c", &value);
        head = AddTail(head, value);
    }
    return head;
}
int main(){
    int E,i;
    char ch,M;
    int N;
    scanf("%d",&N);
    node head=Input();
    Traverser(head);
    scanf("%d",&E);
    for (i = 0; i < E;++i){
        scanf(" %c", &ch);
        //커서를 왼쪽으로 한 칸 옮김
        if(ch=='L'){  
            N=N-1;
            if(N<=0){
                N=0;
            }
        }
        //커서를 오른쪽으로 한 칸 옮김
        else if(ch=='D'){
            N=N+1;
        }
        //임의의 값이라는 문자를 커서 왼쪽에 추가함
        else if(ch=='P'){  
            scanf(" %c",&M);
            head=AddAt(head,M,N);
            N=N+1;
            Traverser(head);

        }
        //커서 왼쪽에 있는 문자를 삭제함
        else if(ch=='B'){  
            N=N-1;
            if(N<0){
                if(N<=0){
                    N=0;
                }
                printf("continue ");
            }
            else{
                printf("%d",N);
                head = DelAt(head, N);
                Traverser(head);
            }
        }
    }
}