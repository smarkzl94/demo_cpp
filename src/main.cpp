#include <iostream>
#include <string>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::cout << "Hello, C++ demo!" << std::endl;

    int x = 3;
    int y = 5;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;

    std::string name = "Cursor";
    std::cout << "Welcome, " << name << "!" << std::endl;

    return 0;
}
