#include<stdio.h>
# include <malloc.h>


void f(int * q){
    * q = 200;

    // 释放q的内存。在main中打印出垃圾值。
    free(q);
}

int main(void){
    int * p = (int *) malloc(sizeof(int));

    *p = 10;

    printf("%d\n", *p);
    f(p);
    printf("%d\n", *p);
    return 0;
}

