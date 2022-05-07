#include <iostream>

struct Employee
{
    // int bad; // don't do this, always have {} so will get auto-assigned a value if not given one
    int id{};
    int age{};
    std::string position{};
    double salary{ 30000.00 }; // add a default salary
};

struct Company
{
    int numberOfEmployees{};
    Employee CEO{};  // can also have a struct nested within another struct
};

// const used so make copy to avoid changing values
// pass by reference &
void printEmployee(const Employee& employee) {
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Position: " << employee.position << '\n';
}

void printCompany(const Company& company) {
    std::cout << "company CEO salary: " << company.CEO.salary << '\n';
}


int main() {
    Employee joe;
    joe.age = 22;
    std::cout << "joes age is " << joe.age << '\n';
    std::cout << "default salary is " << joe.salary << '\n';

    Employee kyle { 21, 42, "boss", 5000000 };
    std::cout << "kyles position is " << kyle.position << '\n';

    printEmployee(kyle);

    Company disney{ 222, kyle };
    printCompany(disney);

    // pointers
    Employee* ptrToJoe{ &joe };
    // std::cout << ptrToJoe.id;  // can't directly access properties with dot notation on pointers
    // first need to use deference operator on the pointer
    std::cout << "joes age with a pointer and deference " << (*ptrToJoe).age << '\n';
    // but much cleaner is to use the -> operator
    std::cout << "joes salary from pointer with -> operator " << ptrToJoe->salary << '\n';

    return 0;
}