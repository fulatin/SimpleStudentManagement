#include "Manager.h"
#include "Student.h"
#include <stdio.h>
int main() {
  char buffer[MAX_NAME_LEN] = "dwdw";
  addStudent(buffer, 19);
  printf("%d", findStudentByName(buffer)->age);
  printf("Haven't finished yet");
}
