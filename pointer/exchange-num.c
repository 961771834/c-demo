/* 
 * 2019年1月3日20:52:25
 * 通过指针互换函数
 */

#include <stdio.h>
void exchangeNum(int * i, int * j){
    int t;
    t = *i;
    *i = *j;
    *j = t;  
}

int main(int argc, char const *argv[])
{
  /* code */
  int i = 5;
  int j = 3;
  exchangeNum(&i,&j);
  printf("i = %d, j = %d",i,j);
  return 0;
}
