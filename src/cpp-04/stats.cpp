#include "stats.h"

long long sum_values(const int* values, int count) {
    long long total = 0;
    for (int i = 0; i < count; ++i) total += values[i];
    return total;
}

int min_value(const int* values, int count) {
    int result = values[0];
    for (int i = 1; i < count; ++i) if (values[i] < result) result = values[i];
    return result;
}

int max_value(const int* values, int count) {
    int result = values[0];
    for (int i = 1; i < count; ++i) if (values[i] > result) result = values[i];
    return result;
}
