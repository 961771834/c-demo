#include"../common.h"
#include"SString.H"
#include"SString-operation.c"

void get_next(SString T,int next[]){
  int j = 1,k = 0;
  next[1] = 0;
  while(j<T[0]){
    if(k == 0 || T[j] == T[k]){
        ++j;
        ++k;
        next[j] = k;
    }else{
      k = next[k];
    }
  } 
}

int Index_KMP(SString S,SString T,int pos,int next[]){
  int i = pos,j = 1;
  while(i<=S[0] && j<= T[0]){
    if(j==0|| S[i] == T[j]){
      ++i;
      ++j;
    }else{
      j=next[j];
    }
  }
  if(j>T[0]){
    return i-T[0];
  }else{
    return  0;
  }
}

void main()
 {
   int i,j,*p;
   SString s1,s2; /* 以教科书中图4.5为例 */
   StrAssign(s1,"acabaabaabcacaabc");
   printf("主串为: ");
   StrPrint(s1);
   StrAssign(s2,"abaabcac");
   printf("子串为: ");
   StrPrint(s2);
   i=StrLength(s2);
   p=(int*)malloc((i+1)*sizeof(int)); /* 生成s2的next数组 */
   get_next(s2,p);
   printf("子串的next函数为: ");
   for(j=1;j<=i;j++)
     printf("%d ",*(p+j));
   printf("\n");
   i=Index_KMP(s1,s2,1,p);
   if(i)
     printf("主串和子串在第%d个字符处首次匹配\n",i);
   else
     printf("主串和子串匹配不成功\n");
 }


