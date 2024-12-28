#include "../Manager.h"
#include <crow.h>
#include <crow/app.h>
#include <cstring>
#include <vector>

using std::vector;
int main() {
  crow::SimpleApp app;
  char buf[MAX_NAME_LEN] = "man";
  addStudent(buf, 12);

  addStudent(buf, 12);
  addStudent(buf, 12);
  addStudent(buf, 12);
  CROW_ROUTE(app, "/student/all")([]() {
    crow::json::wvalue response;

    int count = 0;
    vector<Stu> res;
    for (int i = 0; i < MAX_STUDENT; ++i) {
      if (Students[i]) {
        response[count]["name"] = Students[i]->name;
        response[count]["age"] = Students[i]->age;
        Stu tmp;
        strcpy(tmp.name, Students[i]->name);
        tmp.age = Students[i]->age;
        res.push_back(tmp);
        count++;
      }
    }
    return response;
  });
  app.port(2021).multithreaded().run();
  return 0;
}
