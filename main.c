#include "Manager.h"
#include "Student.h"
#include <stdio.h>
int main() {
  char buffer[MAX_NAME_LEN] = "dwdw";

  int shouldExit = 0;

  while (!shouldExit) {
    printf("请输入你要进行的操作：\n"
           "(1) 添加一个学生\n"
           "(2) 删除一个学生\n"

           // TODO

           "(3) 输出所有学生\n"
           "(4) 退出\n");
    int op;
    scanf("%d", &op);
    if (op == 1) {

      printf("请输入姓名：");
      scanf("%s", buffer);
      int age;
      printf("请输入年龄：");
      scanf("%d", &age);
      if (!addStudent(buffer, age))
        printf("添加失败");
    } else if (op == 2) {

    } else if (op == 3) {
      printAllStudent();

    } else if (op == 4) {
      saveToFile("data");
      shouldExit = 1;
    }
  }

  return 0;
}
