#include <iostream>
#include <memory>
#include <string>
#include <vector>

class GraphNode {
public:
  explicit GraphNode(std::string name) : name_(std::move(name)) {}

  const std::string &name() const { return name_; }

  void addNeighbor(const std::shared_ptr<GraphNode> &other) {
    neighbors_.emplace_back(other);
  }

  void printNeighbors() const {
    std::cout << name_ << " ->";
    for (const auto &weak : neighbors_) {
      if (auto neighbor = weak.lock()) {
        std::cout << " " << neighbor->name();
      } else {
        std::cout << " (expired)";
      }
    }
    std::cout << "\n";
  }

private:
  std::string name_;
  std::vector<std::weak_ptr<GraphNode>> neighbors_;
};

int main() {
  auto a = std::make_shared<GraphNode>("A");
  auto b = std::make_shared<GraphNode>("B");
  auto c = std::make_shared<GraphNode>("C");

  a->addNeighbor(b);
  b->addNeighbor(c);
  c->addNeighbor(a);

  std::cout << "cycle A->B->C->A\n";
  a->printNeighbors();
  b->printNeighbors();
  c->printNeighbors();
  std::cout << "use_count A=" << a.use_count() << " B=" << b.use_count()
            << " C=" << c.use_count() << " (all 1, no cycle leak)\n";

  c.reset();
  std::cout << "after drop C:\n";
  b->printNeighbors();
  return 0;
}
