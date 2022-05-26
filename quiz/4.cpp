#include <iostream>
#include <array>
#include <algorithm>

struct Student {
    std::string name{};
    int points{};
};

int main() {

    std::array<Student, 3> students{
        {
            { "Albert", 9 },
            { "Charlie", 4 },
            { "Glenda", 12 }
        }
    };

    auto findMax {
        [](Student& a, Student& b) {
            return a.points < b.points;
        }
    };

    auto bestStudent = std::max_element(students.begin(), students.end(), findMax);

    // const auto bestStudent{
    //     std::max_element(students.begin(), students.end(), [](const auto& a, auto& b) {
    //         return (a.points < b.points);
    //     })
    // };

    std::cout << bestStudent->name << " is the best student" << '\n';





    return 0;
}