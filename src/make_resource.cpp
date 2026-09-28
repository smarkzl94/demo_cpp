#include <iostream>

class Resource {
public:
  Resource() { std::cout << "ctor\n"; }
  Resource(const Resource &) { std::cout << "copy\n"; }
  Resource(Resource &&) noexcept { std::cout << "move\n"; }
  ~Resource() { std::cout << "dtor\n"; }
};

Resource make_resource() {
  Resource r;
  return r; // NRVO 直接构造进调用方；即使未优化也走移动，不会拷贝
}

int main() {
  Resource x = make_resource();
  // 期望大致看到：ctor / move（或只有 ctor，被 NRVO 优化掉）/ dtor...
  // 不应出现 copy
  // (void)x;
  return 0;
}
