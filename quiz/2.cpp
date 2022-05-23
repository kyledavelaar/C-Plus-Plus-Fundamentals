#include <iostream>
#include <vector>
#include <algorithm>


struct Student {
    std::string firstName{};
    int grade{};
};

bool compare(const Student& s1, const Student& s2) {
    return (s1.grade > s2.grade);
}

int main() {

    int studentCount{};
    std::cout << "how many students? ";
    std::cin >> studentCount;

    std::vector<Student> students(studentCount);

    for (int i = 0; i < studentCount; i++) {
        Student student;
        std::cout << "enter name student " << i + 1 << ": ";
        std::cin >> student.firstName;
        std::cout << "enter grade of student " << i + 1 << ": ";
        std::cin >> student.grade;
        students[i] = student;
    }
    std::sort(students.begin(), students.end(), compare);

    for (const Student student: students) {
        std::cout << student.firstName << " got a grade of " << student.grade << '\n';
    }




    return 0;
}