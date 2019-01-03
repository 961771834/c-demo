/* 
* 2019年1月3日20:13:08
* 加深理解pointer的概念
 */
#include <stdio.h>


int main(int argc, char const *argv[])
{

  int i = 5;
  int * p;
  int * q;
  p = &i;
  // ‘int *’ convert int:   p = &i;

  // *p = *q;
  p = q;
  printf("%d\n",*q);
  return 0;
}
