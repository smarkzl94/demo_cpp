#include <iostream>
#include <memory>
#include <vector>

struct Widget {
  int id;
};

class ObjectPool {
public:
  std::shared_ptr<Widget> acquire() {
    Widget *obj = nullptr;
    if (!pool_.empty()) {
      obj = pool_.back().release();
      pool_.pop_back();
    } else {
      obj = new Widget{++next_id_};
    }

    return std::shared_ptr<Widget>(obj, [this](Widget *p) {
      pool_.emplace_back(p);
    });
  }

  std::size_t available() const { return pool_.size(); }

private:
  std::vector<std::unique_ptr<Widget>> pool_;
  int next_id_ = 0;
};

int main() {
  ObjectPool pool;

  {
    auto a = pool.acquire();
    auto b = pool.acquire();
    std::cout << "got id=" << a->id << " and id=" << b->id
              << ", available=" << pool.available() << "\n";
  }

  std::cout << "after release, available=" << pool.available() << "\n";

  auto c = pool.acquire();
  std::cout << "reused id=" << c->id << ", available=" << pool.available()
            << "\n";
  return 0;
}
