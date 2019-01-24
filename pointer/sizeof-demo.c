#include <stdio.h>

void main(){
    char ch ='A';
    int i = 99;
    double r = 99.99;
    char * p = &ch;
    int * q = &i;
    double * x = &r;
    printf("%d %d %d\n",sizeof(p),sizeof(q),sizeof(x));
}