#include "Manager.h"
#include "Student.h"

Stu *Students[MAX_STUDENT];
int addStudent(char name[MAX_NAME_LEN], int age) {
  Stu *newStu = AllocNewStudent(name, age);
  if (!newStu) {
    return 0;
  }
  int i;
  for (i = 0; i < MAX_STUDENT; ++i) {
    if (!Students[i]) {
      Students[i] = newStu;
      break;
    }
  }
  if (i == MAX_STUDENT) {
    return 0;
  } else {
    return -1;
  }
}

Stu *findStudentByName(char name[MAX_NAME_LEN]) {
  for (int i = 0; i < MAX_STUDENT; ++i) {
    if (Students[i]) {
      int flg = 1;
      for (int j = 0; j < MAX_NAME_LEN; ++j) {
        if (Students[i]->name[j] != name[j]) {
          flg = 0;
          break;
        }
      }
      if (flg) {
        return Students[i];
      }
    }
  }
  return 0;
}
