#include<stdio.h>
 
// enum DAY
// {
//       MON=1, TUE, WED, THU, FRI, SAT, SUN
// };
 

enum DAY
{
      MON, TUE, WED=1, THU, FRI, SAT, SUN
}; 
int main()
{
    enum DAY day;
    day = TUE;
    printf("%d\n",day);
    return 0;
}