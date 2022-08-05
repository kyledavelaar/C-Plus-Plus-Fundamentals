#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void example1() {
    // Create an unordered_map of three strings (that map to strings)
    std::unordered_map<std::string, std::string> u = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };

    // Helper lambda function to print key-value pairs
    auto print_key_value = [](const auto& key, const auto& value) {
        std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
    };

    std::cout << "Iterate and print key-value pairs of unordered_map, being\n"
                 "explicit with their types:\n";
    for( const std::pair<const std::string, std::string>& n : u ) {
        print_key_value(n.first, n.second);
    }

    std::cout << "\nIterate and print key-value pairs using C++17 structured binding:\n";
    for( const auto& [key, value] : u ) {
        print_key_value(key, value);
    }

    // Add two new entries to the unordered_map
    u["BLACK"] = "#000000";
    u["WHITE"] = "#FFFFFF";

    std::cout << "\nOutput values by key:\n"
                 "The HEX of color RED is:[" << u["RED"] << "]\n"
                 "The HEX of color BLACK is:[" << u["BLACK"] << "]\n\n";

    std::cout << "Use operator[] with non-existent key to insert a new key-value pair:\n";
    print_key_value("new_key", u["new_key"]);

    std::cout << "\nIterate and print key-value pairs, using `auto`;\n"
                 "new_key is now one of the keys in the map:\n";
    for( const auto& n : u ) {
        print_key_value(n.first, n.second);
    }
}

std::unordered_map<int, int> createCache(const std::vector<int>& arr) {
    std::unordered_map<int, int> cache {};

    for (const auto& num: arr) {
        if (cache.find(num) == cache.end()) { // not in cache yet
            cache[num] = 1;
        } else {
            cache[num]++;
        }
    }
    return cache;
}

int main()
{
    // example1();
    std::vector<int> arr{ 1,2,3,1,1,3 };
    std::unordered_map<int, int> cache{ createCache(arr) };
    for( const auto& n: cache) {
        std::cout << "number: " << n.first << " times: " << n.second << std::endl;
    }

    return 0;
}