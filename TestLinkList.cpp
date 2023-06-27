/*
  Author: Hexa
  Modified time:2023-06-16 17:16:42
  Goal:
*/

#include <iostream>
using namespace std;
typedef struct ListNode
{
    /* data */
    int data;
    struct ListNode *next;

} ListNode, *Linklist;
/*创建一个链表，返回头指针*/
ListNode CreatLinkLsit()
{
    ListNode first = {.next = NULL};
    return first;
}
//输出链表的各个结点的值    
void PrintAll(ListNode *Head)
{
    ListNode *p = Head->next;
    if (p == NULL)
    {
        printf("It's empty!");
        return;
    }
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
//按序号返回节点,index从1开始，找不到则返回NULL
ListNode* GetElementbyIndex(Linklist &Head,int index){
    if(index < 1){
        return NULL;
    }
    int n = 1;
    ListNode* s = Head->next;
    while(n < index && s != NULL){
        s = s->next;
        n++;
    }
    // printf("The %dth one is %d",index,s->data);
    return s;
}

//按值返回节点，index从1开始，找不到则返回NULL
ListNode* GetElementbyValue(Linklist &Head,int value){
    int n = 1;
    ListNode* s = Head->next;
    while(value != s->data && s != NULL){
        s = s->next;
        n++;
    }
    printf("The %dth one is %d",n,s->data);
    return s;
}
//尾部插入值
ListNode *InsertValuefromScanfbyTail(Linklist &Head){
    ListNode *s,*nail;
    nail = Head;
    int in;
    scanf("%d", &in);
    while(in != 9999){
        s = (Linklist)malloc(sizeof(ListNode));
        s->data = in;
        nail->next = s;
        nail = s;
        scanf("%d", &in);
    }
    nail->next = NULL;
    return Head;
}
//c++中&有引用的作用，放在函数形参中可以当指针用。
ListNode *InsertValuefromScanfbyHead(Linklist &Head)
{
    ListNode *s;
    int in;
    scanf("%d", &in);
    while (in != 9999)
    {
        /* code */
        s = (ListNode *)malloc(sizeof(ListNode));
        s->data = in;
        s->next = Head->next;
        Head->next = s;
        scanf("%d", &in);
       
    }
    //可省略
    return Head;

    
}

//插入节点，根据位置插入节点，返回头指针，位置不合法则返回NULL
ListNode* InsertNodebyIndex(Linklist &Head,int index,int value){
    if(index <= 0)return NULL;
    Linklist SearchPointer = GetElementbyIndex(Head,index - 1);
    ListNode* NodeofValue = (Linklist)malloc(sizeof(ListNode));
    NodeofValue->data = value;
    if(SearchPointer == NULL)return NULL;
    NodeofValue->next = SearchPointer->next;
    SearchPointer->next = NodeofValue;
    return Head;
}

//删除节点，根据位置删除节点，返回头指针，位置不合法则返回NULL。
ListNode* DeleteNodebyIndex(Linklist &Head,int index){
    if(index <= 0)return NULL;
    Linklist SearchPointer = GetElementbyIndex(Head,index - 1);
     
    if(SearchPointer == NULL || SearchPointer->next  == NULL)return NULL;
    ListNode* Tem = SearchPointer->next;
    SearchPointer->next = SearchPointer->next->next;
    free(Tem);
    return Head;
}

//求表长,返回长度
int Length(Linklist Head){
    int i = 0;
    ListNode* TraversalList = Head->next;
    while(TraversalList != NULL){
        TraversalList = TraversalList->next;
        i++;
    }
    return i;
}

int main()
{
    ListNode* Head =  (ListNode*)malloc(sizeof(ListNode));
    Head->next = NULL;
    // Head = InsertValuefromScanfbyHead(Head);
    Head = InsertValuefromScanfbyTail(Head);
    PrintAll(Head);
    printf("Please input the deleted index of node");
    int i = 0;
    cin>>i;
    DeleteNodebyIndex(Head,i);
    PrintAll(Head);
    return 0;
}