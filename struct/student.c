#include <stdio.h>

struct Student{
  int age;
  float score;
  char sex;
};

void inputStudent(struct Student *stud){
  // stud->age = 12;
  // stud->score=100;
  // stud->sex='F';
  printf("请输入学生的信息:");
  printf("age =");
  scanf("%d",&stud->age);
  printf("score=");
  scanf("%f",&stud->score);
  printf("sex=");
  scanf("%c",&stud->sex);
};

void outputStudent(struct Student *stud){
  printf("学生的信息:\n");
  printf("age:%d\n",stud->age);
  printf("score:%f\n",stud->score);
  printf("sex:%c\n",stud->sex);
}

int main(int argc, char const *argv[])
{
  /* code */
  struct Student student;
  inputStudent(&student);
  outputStudent(&student);
  return 0;
}
