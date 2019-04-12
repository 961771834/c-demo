typedef struct LNode /* 结点类型 */
{
  ElemType data;
  struct LNode *next;
}LNode,*Link,*Position;

typedef struct LinkList /* 链表类型 */
{
  Link head,tail;
  int len;
}LinkList;

