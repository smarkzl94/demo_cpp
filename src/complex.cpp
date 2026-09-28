#include <iostream>

class Complex {
private:
  double value;

public:
  Complex(double value = 0) : value(value) {}

  Complex operator+(const Complex &other) const {
    return Complex(value + other.value);
  }
  Complex operator-(const Complex &other) const {
    return Complex(value - other.value);
  }
  Complex operator*(const Complex &other) const {
    return Complex(value * other.value);
  }
  Complex operator/(const Complex &other) const {
    if (other.value == 0) {
      throw std::invalid_argument("Division by zero");
    }
    return Complex(value / other.value);
  }

  bool operator==(const Complex &other) const { return value == other.value; }

  bool operator!=(const Complex &other) const { return value != other.value; }

  Complex operator-() const { return Complex(-value); }
};

// 练习 2：字符串类
// 实现简化版的 `MyString` 类，重载：
// * `+`（拼接）
// * `+=`
// * `[]`
// * `==`、`!=`、`<`
// * `<<`
class MyString {

private:
  std::string value;

public:
  explicit MyString(std::string value = "") : value(value) {}

  MyString operator+(const MyString &other) const {
    return MyString(this->value + other.value);
  }

  MyString &operator+=(const MyString &other) {
    this->value = this->value + other.value;
    return *this;
  }

  char operator[](const int index) { return this->value[index]; }

  char operator[](const int index) const { return this->value[index]; }

  bool operator==(const MyString &other) const {
    return this->value == other.value;
  }

  bool operator!=(const MyString &other) const {
    return this->value != other.value;
  }

  bool operator<(const MyString &other) const {
    return this->value < other.value;
  }

  friend std::ostream &operator<<(std::ostream &os, const MyString &myString) {
    return os << myString.value;
  }
};

int main() {
  // Complex a(3, 4);
  // Complex b(1, 2);

  return 0;
}
