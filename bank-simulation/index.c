 #define Qu 4 /* 客户队列数 */
 #define Khjg 5 /* 两相邻到达的客户的时间间隔最大值 */
 #define Blsj 30 /* 每个客户办理业务的时间最大值 */
 #include"../common.h"

// 有序链表
typedef struct {
  int OccurTime; /* 事件发生时刻 */
  int NType; /* 事件类型，Qu表示到达事件,0至Qu-1表示Qu个窗口的离开事件 */
}Event,ElemType; /* 事件类型，有序链表LinkList的数据元素类型 */

#include"link-list.h"
typedef LinkList EventList; /* 事件链表类型，定义为有序链表 */
#include"link-list-operation.c"


// 队列相关部分
 typedef struct
 {
   int ArrivalTime; /* 到达时刻 */
   int Duration; /* 办理事务所需时间 */
 }QElemType; /* 定义QElemType(队列的数据元素类型)为结构体类型; */

#include"link-queue.h"
#include"link-queue-operation.c"

/* 程序需要的变量 */
EventList ev; /* 事件表 */
Event en; /* 事件 */
Event et; /* 临时变量 */
LinkQueue q[Qu]; /* Qu个客户队列 */
QElemType customer; /* 客户记录 */
int TotalTime=0,CustomerNum=0; /* 累计客户逗留时间,客户数(初值为0) */
int CloseTime; /* 银行营业时间(单位是分) */

 int cmp(Event a,Event b)
 { /* 依事件a的发生时刻<、=或>事件b的发生时刻分别返回-1、0或1 */
   if(a.OccurTime==b.OccurTime)
     return 0;
   else
     return (a.OccurTime-b.OccurTime)/abs(a.OccurTime-b.OccurTime);
 }

void OpenForDay(){
    int i;
    InitList(&ev);
    en.OccurTime=0; /* 设定第一个客户到达事件 */
    en.NType=Qu; /* 到达 */
    OrderInsert(&ev,en,cmp); /* 插入事件表 */
    for(i=0;i<Qu;++i) /* 置空队列 */
      InitQueue(&q[i]);
}

void Random(int *d,int *i){
  *d=rand()%Blsj+1; /* 1到Blsj之间的随机数 */
  *i=rand()%Khjg+1; /* 1到Khjg之间的随机数 */
}

int Minimum(LinkQueue Q[]){
  int l[Qu];
  int i,k;
  for(i=0;i<Qu;i++)
    l[i] = QueueLength(Q[i]);
  k=0;
  for(i = 1;i<Qu;i++)
    if(l[i] < l[0]){
      l[0] = l[i];
      k = i;
    }
  return k;
}


void CustomerArrived(){
  /* 处理客户到达事件  en.NType=Qu*/
  QElemType f;
  int durtime,intertime,i;
  ++CustomerNum;
  Random(&durtime,&intertime);
  et.OccurTime = en.OccurTime + intertime;
  et.NType = Qu;
  if(et.OccurTime<CloseTime)
    OrderInsert(&ev,et,cmp);
  i=Minimum(q);
  f.ArrivalTime = en.OccurTime;
  f.Duration = durtime;
  EnQueue(&q[i],f);
  // 表示队列中在插入前为空
  if(QueueLength(q[i])==1){
    et.OccurTime = en.OccurTime + durtime;
    et.NType = i;
    OrderInsert(&ev,et,cmp);
  }
}

void CustomerDeparture(){
  int i;
  i=en.NType;
  DeQueue(&q[i],&customer);
  // 发生时间减去到达时间
  TotalTime += en.OccurTime -  customer.ArrivalTime;
  if(!QueueEmpty(q[i])){
    GetHead_Q(q[i],&customer);
    // 事件队列插入一个客户离开事件。
    et.OccurTime = en.OccurTime + customer.Duration;
    et.NType = i;
    OrderInsert(&ev,et,cmp);
  } 
}



void Bank_Simulation(){
   Link p;
   OpenForDay();
   while(!ListEmpty(ev)){
     DelFirst(&ev,GetHead(ev),&p);
     en.OccurTime = GetCurElem(p).OccurTime;
     en.NType = GetCurElem(p).NType;
     if(en.NType == Qu){
       CustomerArrived();
     }else{
       CustomerDeparture();
     }
   };
  printf("顾客总数:%d, 所有顾客共耗时:%d分钟, 平均每人耗时: %d分钟\n",CustomerNum,TotalTime,TotalTime/CustomerNum);
};

void main(){
  printf("请输入银行营业时间长度(单位:分)\n");
  scanf("%d",&CloseTime);                                                                                                                                                                 
  Bank_Simulation();
}