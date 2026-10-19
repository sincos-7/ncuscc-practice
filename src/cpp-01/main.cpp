#include <iostream>

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        return 1;
    }

    int count = 0;
    int sum = 0;
    int min_num = 0;
    int max_num = 0;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        count++;
        sum += x;
        if (i == 0) {
            min_num = x;
            max_num = x;
        } else {
            if (x < min_num) min_num = x;
            if (x > max_num) max_num = x;
        }
    }

    std::cout << "count=" << count << "\n";
    std::cout << "sum=" << sum << "\n";
    std::cout << "min=" << min_num << "\n";
    std::cout << "max=" << max_num << "\n";
    return 0;
}
