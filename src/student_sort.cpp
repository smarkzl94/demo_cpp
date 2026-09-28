#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
  std::string name;
  int score;
};

int main() {
  std::vector<Student> students = {
      {"Alice", 90},
      {"Bob", 85},
      {"Carol", 90},
      {"Dave", 85},
  };

  std::sort(students.begin(), students.end(),
            [](const Student &a, const Student &b) {
              // TODO: 成绩降序；成绩相同则姓名升序
              if (a.score > b.score) {
                return true;
              } else if (a.score < b.score) {
                return false;
              } else {
                return a.name < b.name;
              }
            });

  for (const auto &s : students) {
    std::cout << s.name << " " << s.score << "\n";
  }
  return 0;
}
