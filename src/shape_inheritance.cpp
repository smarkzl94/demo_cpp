#include <cmath>
#include <iostream>

// ### 练习：图形继承
// 设计继承体系：
// * 基类 `Shape`（名称）
// * `Circle`：半径，面积 = π * r * r
// * `Rectangle`：长、宽，面积 = 长 * 宽
// * 都应有 `area()` 方法
class Shape {
public:
  Shape(std::string name) : name(name) {}
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual double getPerimeter() const = 0;

private:
  std::string name;
};

class Rectangle : public Shape {
private:
  double height;
  double width;

public:
  Rectangle(std::string name, double height, double width)
      : Shape(name), height(height), width(width) {}
  double getArea() const { return height * width; }
  double getPerimeter() const { return 2 * (height + width); }
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(std::string name, double radius) : Shape(name), radius(radius) {}
  double getArea() const { return 3.14 * radius * radius; }
  double getPerimeter() const { return 2 * 3.14 * radius; }
};

class Triangle : public Shape {
private:
  double a;
  double b;
  double c;

public:
  Triangle(std::string name, double a, double b, double c)
      : Shape(name), a(a), b(b), c(c) {}
  double getArea() const { 
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c)); }
  double getPerimeter() const { return a + b + c; }
};

int main() {
  Shape *shapes[] = {
      new Rectangle("rect", 3, 4),
      new Circle("circle", 2),
      new Triangle("tri", 3, 4, 5),
  };

  double totalArea = 0;
  for (Shape *shape : shapes) {
    totalArea += shape->getArea();
  }
  std::cout << "Total area: " << totalArea << std::endl;

  for (Shape *shape : shapes) {
    delete shape;
  }
  return 0;
}
