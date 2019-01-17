/* 
 * 2019年1月17日18:19:03
 * 需要第一个元素和length才能确定数组
 */

#include <stdio.h>

void printArray(int * array,int len){
  for(int i = 0;i<len;i++){
    printf("%d",*(array+i));
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  int a[5] = {1,2,3,4,5};
  int b[100] = {1,2};
  // a变量代表的是数组第一个元素的指针变量
  // printArray(a,5);
  printArray(b,100);
  return 0;
}
