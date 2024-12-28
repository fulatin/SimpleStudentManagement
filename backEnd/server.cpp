#include "../Manager.h"
#include <crow.h>
#include <crow/app.h>
#include <cstring>
#include <string>
#include <vector>
using std::string;
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
  CROW_ROUTE(app, "/student/add")
      .methods("POST"_method)([&](const crow::request &req) {
        auto x = crow::json::load(req.body);
        string name = x["name"].s();
        for (int i = 0; i < MAX_NAME_LEN && i < name.size(); ++i) {
          buf[i] = name[i];
        }
        if (addStudent(buf, x["age"].i())) {
          return crow::response(200);
        } else {
          return crow::response(503);
        }
      });
  app.port(2021).multithreaded().run();
  return 0;
}
