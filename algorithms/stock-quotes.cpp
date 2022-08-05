#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


/*

    Stock quotes are stored in an array in order of date. The stock profit is the difference in prices in buying and selling stock. Each day, you can either buy one unit of stock, sell any number of stock units you have already bought, or do nothing. Therefore, the most profit is the maximum difference of all pairs in a sequence of stock prices.

    [ 1, 2, 3, 4, 5, 6 ]        => 15  (buy at 1,2,3,4,5 and then sell all at 6)
    [ 6, 5, 4, 3, 2, 1 ]        => 0   (nothing to buy for profit)
    [ 1, 6, 5, 10, 8, 7 ]       => 18  (buy at 1,6,5 and sell all at 10)
    [ 1, 2, 10, 3, 2, 7, 3, 2 ] => 26  (buy at 1,2 and sell them at 10. Then buy at 3,2 and sell them at 7)

    [ 1, 10, 1, 100 ] -> 288 (buy at 1, 10, 1, sell at 100)
    [ 1, 10, 1, 12 ] -> 20 (buy 1, sell 10, buy 1, sell at 12)
    [ 1, 10, 1, 12 ] -> 24 (buy at 1, by at 10, buy at 1, sell at 12)

    - if bigger number later, buy
    - if never a bigger number, do nothing
    - if biggest number left, sell

    - order prices from lowest to highest (sorted)
    - loop through prices in original order
        - find index of price in sorted
        - if price is highest in sorted -> sell (if possible) if can't do nothing
        - if price is lowest -> buy
        - remove price from sorted array
*/

bool isHighest(const std::vector<int>& sorted, int num) {
    return sorted[sorted.size() - 1] == num;
}

int getTotalCost(const std::vector<int>& v) {
    int totalCost{ 0 };
    for (const auto& n: v) {
        totalCost += n;
    }
    return totalCost;
}

int most_profit(const std::vector<int>& quotes) {
    std::vector sorted{ quotes };
    std::sort(sorted.begin(), sorted.end());
    int res{0};
    std::vector<int> stocksBought{};

    for (const auto& q : quotes) {
        int lastIndex{ static_cast<int>(sorted.size()) - 1 };
        if (sorted[lastIndex] == q) {
            // std::cout << "highest " << q << std::endl;
            int cost{ getTotalCost(stocksBought) };
            // std::cout << "total cost: " << cost << std::endl;
            int profit{ (static_cast<int>(stocksBought.size()) * q) - cost };
            // std::cout << "profit: " << profit << std::endl;
            res += profit;
            sorted.erase(sorted.end() - 1);
            stocksBought.clear();
        } else {
            stocksBought.push_back(q);
        }
    }
    return res;
}

int most_profit2(const std::vector<int>& quotes) {
  int profit{0};
  // returns an iterator to the postion with the largest
  auto rolling_max_pos{std::max_element(quotes.begin(), quotes.end())};
  std::cout << "rolling: " << *rolling_max_pos << std::endl;

  for (auto it{quotes.begin()}; it != quotes.end(); it++) {
    std::cout << "it: " << *it << std::endl;
    // it is also an iterator
    if (it > rolling_max_pos) {
      rolling_max_pos = std::max_element(it, quotes.end());
    }

    // *pointer gets value of what pointer is pointing at
    profit += std::max(*rolling_max_pos - *it, 0);
  }

  return profit;
}


int main() {
    std::vector<int> stocks1{ 1, 2, 3, 4, 5, 6 }; // 15
    std::cout << most_profit2(stocks1) << std::endl;
    // std::vector<int> stocks1{ 1, 2, 3, 4, 5, 6 }; // 15
    // std::cout << most_profit(stocks1) << std::endl;
    // std::vector<int> stocks2{ 1, 6, 5, 10, 8, 7 };
    // std::cout << most_profit(stocks2) << std::endl; // 18
    // std::vector<int> stocks3{ 1, 2, 10, 3, 2, 7, 3, 2 };
    // std::cout << most_profit(stocks3) << std::endl; // 26
    // std::vector<int> stocks4{ 6, 5, 4, 3, 2, 1 };
    // std::cout << most_profit(stocks4) << std::endl; // 0
    // std::vector<int> stocks5{ 1, 10, 1, 100 };
    // std::cout << most_profit(stocks5) << std::endl; // 288
    // std::vector<int> stocks6{ 1, 10, 1, 12 };
    // std::cout << most_profit(stocks6) << std::endl; // 24
    // std::vector<int> stocks7{ 6633, 4024, 4977, 8284, 9377, 1454, 6356, 9919, 6870, 871, 7402, 202, 9799, 1321, 6746, 6812, 8879, 8887, 2571, 576, 5981, 2269, 4694, 1589, 8206, 5053, 5648, 4555, 4901, 9059, 1090, 2842, 9584, 3338, 3351, 7302, 1379, 4333, 9060, 3644, 7916, 2553, 4596, 9355, 6368, 790, 2364, 1099, 6856, 3523, 5100, 4053, 6497, 7831, 8431, 6968, 5116, 3405, 4136, 2783, 714, 2268  };
    // std::cout << most_profit(stocks7) << std::endl; // 230788

    return 0;
}