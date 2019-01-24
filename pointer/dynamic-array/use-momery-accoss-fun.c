/* 
 *  跨函数使用内存
 *  该程序有问题：静态变量不能跨函数使用。
 */

#include<stdio.h>

void f(int ** q){
   int i = 5;
   *q = &i;
}



int main(int argc, char const *argv[])
{
  int *p;

  f(&p);

  printf("%d\n",*p);
  return 0;
}
