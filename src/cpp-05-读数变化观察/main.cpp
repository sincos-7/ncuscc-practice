#include <iostream>

int main() {
    int count = 0;
    if (!(std::cin >> count)) return 1;

    long long sum = 0;
    int previous = 0;
    int increases = 0;
    int drops = 0;
    bool first = true;

    for (int i = 0; i < count; i++) {
        int value = 0;
        if (!(std::cin >> value)) return 1;

        sum += value;
        
        if (!first) {
            if (value > previous) increases++;
            else if (value < previous) drops++;
        }
        first = false;
        
        previous = value;
    }

    std::cout << "count=" << count << "\n";
    std::cout << "sum=" << sum << "\n";
    std::cout << "increases=" << increases << "\n";
    std::cout << "drops=" << drops << "\n";

    return 0;
}
