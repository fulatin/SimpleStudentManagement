#include "./Student.h"
#include <memory.h>
#include <stdlib.h>
#include <time.h>
Stu *AllocNewStudent(char name[MAX_NAME_LEN], int age) {
  Stu *res = (Stu *)malloc(sizeof(Stu));
  for (int i = 0; i < MAX_NAME_LEN; ++i) {
    res->name[i] = name[i];
  }
  res->age = age;
  srand((unsigned)time(0));
  res->id = rand();
  return res;
}
