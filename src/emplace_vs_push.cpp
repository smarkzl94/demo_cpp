#include <iostream>
#include <vector>

struct Item {
  int id;

  explicit Item(int id) : id(id) { std::cout << "ctor " << id << "\n"; }
  Item(const Item &other) : id(other.id) {
    std::cout << "copy " << id << "\n";
  }
  Item(Item &&other) noexcept : id(other.id) {
    std::cout << "move " << id << "\n";
  }
};

int main() {
  Item local(1);

  std::cout << "--- push_back 左值 ---\n";
  std::vector<Item> a;
  // TODO: 对 local 使用 push_back，观察是拷贝还是移动
  a.push_back(local);

  std::cout << "--- push_back 右值 ---\n";
  std::vector<Item> b;
  // TODO: push_back 一个临时对象（或 std::move），观察是拷贝还是移动
  b.push_back(Item(2));

  std::cout << "--- emplace_back ---\n";
  std::vector<Item> c;
  // TODO: 用 emplace_back 直接在容器里构造，观察是否少一次拷贝/移动
  c.emplace_back(3);  

  // (void)local;
  // (void)a;
  // (void)b;
  // (void)c;
  return 0;
}
