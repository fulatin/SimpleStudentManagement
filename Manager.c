#include "Manager.h"
#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
int studentCnt = 0;
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
    studentCnt++;
    return 1;
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

int saveToFile(char path[MAX_NAME_LEN]) {
  FILE *f = fopen(path, "w");
  if (!f)
    return 0;
  fprintf(f, "%d\n", studentCnt);
  for (int i = 0; i < MAX_STUDENT; ++i) {
    Stu *curr = Students[i];
    if (curr) {
      fprintf(f, "%s %d\n", curr->name, curr->age);
    }
  }
  fclose(f);
  return 1;
}

// 找到一个空位的下标 -1： 未找到
int findEmptyPos() {

  for (int i = 0; i < MAX_STUDENT; ++i) {
    if (Students[i] == 0)
      return i;
  }
  return -1;
}

int readFromFile(char path[MAX_NAME_LEN]) {
  FILE *f = fopen(path, "r");
  int n;
  fscanf(f, "%d", &n);
  int readStudentCnt = 0;
  for (int i = 1; i <= n; ++i) {
    char buf[MAX_NAME_LEN];
    int age;
    fscanf(f, "%s", buf);
    fscanf(f, "%d", &age);
    if (addStudent(buf, age)) {
      readStudentCnt++;
    } else {
      return 0;
    }
  }
  return 1;
}

void printAllStudent() {
  for (int i = 0; i < MAX_STUDENT; ++i) {
    if (!Students[i]) {
      printf("姓名： %s, 年龄： %d", Students[i]->name, Students[i]->age);
    }
  }
}

int delStudentById(int id) {
  for (int i = 0; i <= MAX_STUDENT; ++i) {
    if (!Students[i] && Students[i]->id == id) {
      free(Students[i]);
      Students[i] = 0;
      return 1;
    }
  }
  return 0;
}
