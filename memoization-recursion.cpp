#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
    for (auto e : v) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int f1Count = 0;
int f2Count = 0;

// fibonacci called 1205 times
int fibonacci(int count) {
    f1Count += 1;
    if (count == 0) {
        return 0;
    }
    if (count == 1) {
        return 1;
    }
    return fibonacci(count - 1) + fibonacci(count - 2);
}

// only runs 35 times
int memoizedFibonacci(int count) {
    f2Count += 1;

    // need to use 'static' keyword so cache is does not get re-created on each function call
    static std::vector<int> cache {0, 1};
    // print(cache);

    if (count < static_cast<int>(std::size(cache))) {
        return cache[count];
    } else {
        // int result = memoizedFibonacci(count - 1) + memoizedFibonacci(count - 2);
        // cache[count] = result; // does not work b/c vector doesn't have index at that position and doesn't auto create it?
        // return result;
        cache.push_back(memoizedFibonacci(count - 1) + memoizedFibonacci(count - 2));
        return cache[count];
    }
}



int main() {

    for (int i = 0; i < 13; i++) {
        std::cout << fibonacci(i) << ' ';
    }
    std::cout << "\n fibonacci call count: " << f1Count;
    std::cout << "\n ---------------------------- \n";

    for (int i = 0; i < 13; i++) {
        std::cout << memoizedFibonacci(i) << ' ';
    }
    std::cout << "\n fibonacciMemoized call count: " << f2Count << '\n';
    std::cout << "\n ---------------------------- \n";

    // int fibAtN = memoizedFibonacci(12);
    // std::cout << "\n fibAtN: " << fibAtN << '\n';

    // std::vector<int> m{0, 1};
    // print(m);

    return 0;
}