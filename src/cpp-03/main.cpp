#include <iostream>
using namespace std;

int main() {
    const int CAPACITY = 8;
    int window[CAPACITY];
    int kept = 0;      // 当前存了几个数
    int oldest_idx = 0; // 最老的数在数组里的下标

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (kept < CAPACITY) {
            // 没存满，直接往后放
            window[kept] = x;
            kept++;
        } else {
            // 存满了，覆盖最老的位置
            window[oldest_idx] = x;
            oldest_idx = (oldest_idx + 1) % CAPACITY;
        }
    }

    // 计算总和
    int sum = 0;
    for (int i = 0; i < kept; i++) {
        int idx = (oldest_idx + i) % CAPACITY;
        sum += window[idx];
    }

    // 输出 4 行
    cout << "kept=" << kept << endl;
    cout << "oldest=" << window[oldest_idx] << endl;  // oldest 是值，不是下标
    cout << "last=" << window[(oldest_idx + kept - 1) % CAPACITY] << endl;  // last 是最新的那个
    cout << "sum=" << sum << endl;

    return 0;
}

