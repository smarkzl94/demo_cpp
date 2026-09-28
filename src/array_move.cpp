#include <cstddef>
#include <iostream>
#include <utility>

class Array {
public:
  explicit Array(std::size_t n) : data_(new int[n]{}), size_(n) {}

  ~Array() { delete[] data_; }

  Array(const Array &other) : data_(new int[other.size_]{}), size_(other.size_) {
    for (std::size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      Array tmp(other);
      swap(tmp);
    }
    return *this;
  }

  Array(Array &&other) noexcept : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr;
    other.size_ = 0;
  }

  Array &operator=(Array &&other) noexcept {
    if (this != &other) {
      delete[] data_;
      data_ = other.data_;
      size_ = other.size_;
      other.data_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  void swap(Array &other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
  }

  std::size_t size() const { return size_; }
  int *data() const { return data_; }

private:
  int *data_ = nullptr;
  std::size_t size_ = 0;
};

int main() {
  Array a(3);
  a.data()[0] = 1;

  Array b = std::move(a);
  std::cout << "moved-from size=" << a.size() << " (期望 0)\n";
  std::cout << "moved-to size=" << b.size() << " (期望 3)\n";

  Array c(1);
  c = std::move(b);
  std::cout << "after move-assign, b.size=" << b.size() << " (期望 0)\n";
  std::cout << "after move-assign, c.size=" << c.size() << " (期望 3)\n";
  return 0;
}
