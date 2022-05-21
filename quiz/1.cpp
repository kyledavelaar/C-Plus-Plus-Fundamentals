#include <iostream>
#include <array>
#include <numeric>

enum Item {
    potions,
    torches,
    arrows,
    max_items
};

// works but not eloquent
int countTotalItems(const std::array<int, Item::max_items> items) {
    return std::reduce(items.begin(), items.end());
}

// more eloquent way
using items = std::array<int, Item::max_items>;
// use reference instead of very wordy version above
int countItemsEloquently(items& playerItems) {
    return std::reduce(playerItems.begin(), playerItems.end());
}

int main(){
    std::array<int, Item::max_items> playerItems;
    playerItems[Item::potions] = 2;
    playerItems[Item::torches] = 5;
    playerItems[Item::arrows] = 10;

    // a more eloquent way than the 4 lines above
    items playerItems2{ 2, 5, 10 };

    int totalItems = countTotalItems(playerItems);
    std::cout << "total items: " << totalItems << '\n';
    std::cout << "number of torches " << playerItems[1] << '\n';

    int totalItems2 = countItemsEloquently(playerItems2);
    std::cout << "total items: " << totalItems2 << '\n';
    std::cout << "number of torches " << playerItems2[1] << '\n';



    return 0;
}