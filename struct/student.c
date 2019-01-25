#include <stdio.h>

struct Student{
  int age;
  float score;
  char sex;
};

void inputStudent(struct Student *stud){
  stud->age = 12;
  stud->score=100;
  stud->sex='F';
};

void outputStudent(struct Student *stud){
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
