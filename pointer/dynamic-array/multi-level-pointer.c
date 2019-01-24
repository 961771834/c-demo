// 2019年1月24日00:16:25
// 多级指针

#include<stdio.h>

// ** 必须连在一起
void f(int ** m){
    printf("%d",* * m);
}

void g(){
    int i =10;
    int *q = &i;
    f(&q);
}

int main(void){
    g();
    return 0;
}