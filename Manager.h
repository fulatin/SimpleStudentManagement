#ifndef MANAGER_H
#define MANAGER_H
#include "Student.h"
#define MAX_STUDENT 10000

// 返回1 表示成功 0 表示失败
int addStudent(char name[MAX_NAME_LEN], int age);

// 返回找到的学生的地址，0 表示未找到
Stu *findStudentByName(char name[MAX_NAME_LEN]);

// 返回 -1 表示未找到 ，1表示删除成功，0 表示删除失败
int delStudentByName(char name[MAX_NAME_LEN]);

// 保存所有学生到文件
int saveToFile(char path[MAX_NAME_LEN]);

// 从文件中读取学生信息
int readFromFile(char path[MAX_NAME_LEN]);

#endif
