#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> deleteNth(const std::vector<int>& xs, int n) {
  std::vector<int> res;
  std::unordered_map<int, int> ns;
  for (int x : xs)
    if (ns[x]++ < n)
      res.push_back(x);

    // for(auto iter = ns.begin(); iter != ns.end(); ++iter) {
    //     std::cout << iter;
    // }
  return res;
}


// struct num {
//     int number{};
//     int times{};
// };

// std::vector<int> deleteNth(std::vector<int> arr, int n) {
//     std::vector<int> res{};
//     std::vector<num> cache{};
//         for (auto i : arr) {
//             bool hasNumber{ false };
//             for (int c = 0; c < cache.size(); c++) {
//                 if (cache[c].number == i) {
//                     hasNumber = true;
//                     int times = cache[c].times += 1;
//                     if (times <= n) {
//                         res.push_back(i);
//                         cache[c] = { i, times };
//                         // std::cout << "adding to cache: " << i << ": " << times << std::endl;
//                     }
//                 }
//             }
//             if (!hasNumber) {
//                 // std::cout << "adding to cache first time: " << i << ": 1" << std::endl;
//                 res.push_back(i);
//                 cache.push_back({ i, 1 });
//             }
//         }

// //    for(auto i : cache) {
// //         std::cout << i.number << ": " << i.times << std::endl;
// //     }
//     return res;
// }

int main() {

    std::vector<int> v{ 1,2,3,2,3,2,1 };
    std::vector<int> clean{ deleteNth(v, 1) };

    for(auto i : clean) {
        std::cout << i << ", ";
    }

    return 0;
}