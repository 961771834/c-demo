#include<stdio.h>
#include <malloc.h>

int main(void){
    int a[5];
    int len;
    int * pArr;
    printf("请输入你要存放的元素个数");
    scanf("%d",&len);
    // 动态构造了一个数组。
    pArr = (int *) malloc(sizeof(int) * len);
    
    // 对数组进行动态赋值
    for(int i = 0;i<len;i++) {
        scanf("%d\n",&pArr[i]);
    }
    // 打印出数组的值

    for(int i =0;i<len;i++) {
        printf("%d\n",pArr[i]);
    }
    free(pArr);
    return 0;
}