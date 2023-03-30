#include <iostream>
#include <vector>

float find_uniq(const std::vector<float> &v)
{
    float first = v[0];
    float second = v[1];
    float third = v[2];
    float duplicate;
    if (first == second || first == third) {
        duplicate = first;
    } else if (second == third) {
        duplicate = second;
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] != duplicate) {
            return v[i];
        }
    }
}


int main()
{
    std::vector<float> array{1,1,1,1,1,3,1,1,1,1,1};
    // std::vector<float> array{4,1,1,1,1,1,1,1,1,1,1};
    // std::vector<float> array{1,5,1,1,1,1,1,1,1,1,1};
    float res = find_uniq(array);
    std::cout << "answer: " << res << std::endl;
}