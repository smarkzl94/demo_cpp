#include <functional>
#include <iostream>
#include <vector>

class Event {
public:
  void on(std::function<void(int)> callback) {
    callbacks_.push_back(callback);
  }

  void emit(int value) {
    for (auto &callback : callbacks_) {
      callback(value);
    }
  }

private:
  std::vector<std::function<void(int)>> callbacks_;
};

int main() {
  Event click;
  click.on([](int x) { std::cout << "got " << x << "\n"; });
  click.on([](int x) { std::cout << "double " << x * 2 << "\n"; });
  click.emit(7);
  // 期望:
  // got 7
  // double 14
  return 0;
}
