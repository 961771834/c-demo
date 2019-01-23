# include <stdio.h>

# include <malloc.h>

int main(void){
    int i = 5;
    // 分配内存
    int * p = (int *) malloc(4);
    free(p);
    // 赋值
    *p =5;
    return 0;
}