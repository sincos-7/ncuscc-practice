#include "format.h"
#include "stats.h"

#include <iostream>
#include <vector>

int main() {
    int count = 0;
    if (!(std::cin >> count) || count <= 0)
        return 1;

    std::vector<int> values(count);
    for (int& value : values) {
        if (!(std::cin >> value)) return 1;
    }

    print_report(count, sum_values(values.data(), count),
                 min_value(values.data(), count),
                 max_value(values.data(), count));
    return 0;
}
