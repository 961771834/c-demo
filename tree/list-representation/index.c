

typedef int QElemType;
typedef int TElemType;
typedef int ElemType;

#include"../../common.h"
#include"./bit-node.h"
#include"./bit-node-operation.c"

 Status visitT(TElemType e)
 {
   printf("%d\n",e);
   return OK;
 }

void main(){
   int i;
   BiTree T;

   InitBiTree(&T);
   CreateBiTree(&T);

   // 先序遍历二叉树
   printf("%s", "先序遍历二叉树\n");
   PreOrderTraverse(T,visitT);
   // 中序遍历二叉树
   printf("%s", "中序遍历二叉树\n");
   InOrderTraverse(T,visitT);
   // 后序序遍历二叉树
   printf("%s", "后序遍历二叉树\n");
   PostOrderTraverse(T,visitT);
}
