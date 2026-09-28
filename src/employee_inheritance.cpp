#include <iostream>


// ### 练习 1：员工继承体系
// 设计继承体系：
// * 基类 `Employee`（姓名、工号、基本工资）
// * `SalariedEmployee`：固定月薪
// * `HourlyEmployee`：时薪 \* 工作小时
// * 都应有 `calculateSalary()` 方法

class Employee{
    private:
    std::string username;
    std::string userid;
    double baseSalary;
public:
    Employee(std::string username, std::string userid, double baseSalary): username(username), userid(userid), baseSalary(baseSalary){}
};

class SalariedEmployee: public Employee{
private:
     double monthlySalary;
public:
    SalariedEmployee(std::string username, std::string userid, double baseSalary, double monthlySalary): Employee(username, userid, baseSalary), monthlySalary(monthlySalary){}
    
    double calculateSalary() const {
        return monthlySalary;
    }
};

class HourlyEmployee: public Employee{
private:
    double hourlyRate;
    double hoursWorked;
public:
    HourlyEmployee(std::string username, std::string userid, double baseSalary, double hourlyRate, double hoursWorked): Employee(username, userid, baseSalary), hourlyRate(hourlyRate), hoursWorked(hoursWorked){}
    double calculateSalary() const {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    std::cout << "Hello from employee_inheritance.cpp\n";
    return 0;
}
