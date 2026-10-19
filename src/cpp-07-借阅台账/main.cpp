#include <iostream>
#include <string>
#include <map>

int main() {
    int count = 0;
    if (!(std::cin >> count)) return 1;

    std::map<std::string, int> onShelf;
    std::map<std::string, int> borrowed;
    bool has_error = false;

    for (int i = 0; i < count; i++) {
        std::string operation;
        std::string code;
        if (!(std::cin >> operation >> code)) return 1;
        
        if (operation == "add") {
            int copies = 0;
            if (!(std::cin >> copies)) return 1;
            onShelf[code] += copies;
        } else if (operation == "borrow") {
            int copies = 0;
            if (!(std::cin >> copies)) return 1;
            if (onShelf[code] >= copies) {
                onShelf[code] -= copies;
                borrowed[code] += copies;
            } else {
                std::cout << "rejected\n";
                has_error = true;
            }
        } else if (operation == "return") {
            if (borrowed[code] > 0) {
                borrowed[code]--;
                onShelf[code]++;
            } else {
                std::cout << "rejected\n";
                has_error = true;
            }
        }
    }

    // 只有没有错误的时候，才输出统计信息
    if (!has_error) {
        int totalOnShelf = 0;
        int totalBorrowed = 0;
        
        std::map<std::string, std::pair<int, int>> allBooks;
        for (auto& p : onShelf) {
            allBooks[p.first].first = p.second;
            totalOnShelf += p.second;
        }
        for (auto& p : borrowed) {
            allBooks[p.first].second = p.second;
            totalBorrowed += p.second;
        }

        std::cout << "titles=" << allBooks.size() << "\n";
        std::cout << "onShelf=" << totalOnShelf << "\n";
        std::cout << "borrowed=" << totalBorrowed << "\n";
        
        for (auto& p : allBooks) {
            std::cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
        }
    }
    
    return 0;
}
