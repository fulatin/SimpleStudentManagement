#ifndef STUDENT_H
#define STUDENT_H
#define MAX_NAME_LEN 100
struct student {
  char name[MAX_NAME_LEN];
  int age;
};

typedef struct student Stu;
Stu *AllocNewStudent(char name[MAX_NAME_LEN], int age);
#endif
