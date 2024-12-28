#include "../Manager.h"
#include <crow.h>
#include <crow/app.h>
#include <cstring>
#include <string>
#include <vector>
using std::string;
using std::vector;

struct CORSMiddleware {
  struct context {};

  void before_handle(crow::request &req, crow::response &res, context &ctx) {
    // 添加 CORS 头
    res.add_header("Access-Control-Allow-Origin", "*");
    res.add_header("Access-Control-Allow-Methods",
                   "GET, POST, PUT, DELETE, OPTIONS");
    res.add_header("Access-Control-Allow-Headers",
                   "Content-Type, Authorization");

    // 如果是 OPTIONS 请求，直接返回 200
    if (req.method == "OPTIONS"_method) {
      res.code = 200;
      res.end();
    }
    printf("enter");
  }

  void after_handle(crow::request &req, crow::response &res, context &ctx) {
    // 不需要额外处理
  }
};
int main() {
  crow::App<CORSMiddleware> app;
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
