#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <fstream>
#include <mutex>

int thread_count = 0;
std::mutex mtx;

void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    // 当区间小于等于 4 个元素时，串行排序，不再拆线程
    if (right - left <= 4) {
        std::sort(arr.begin() + left, arr.begin() + right + 1);
        return;
    }
    
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    
    bool can_parallel = false;
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (thread_count < 4) {
            thread_count++;
            can_parallel = true;
        }
    }
    
    if (can_parallel) {
        std::thread t(quick_sort, std::ref(arr), left, i - 1);
        quick_sort(arr, i + 1, right);
        t.join();
        std::lock_guard<std::mutex> lock(mtx);
        thread_count--;
    } else {
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
}

int main() {
    std::ifstream fin("data.txt");
    std::vector<int> arr;
    int x;
    while (fin >> x) arr.push_back(x);
    
    std::cout << "排序前：";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";
    
    quick_sort(arr, 0, arr.size() - 1);
    
    std::cout << "排序后：";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";
    
    // 检查是否有序
    bool sorted = true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) sorted = false;
    }
    std::cout << "是否有序：" << (sorted ? "是" : "否") << "\n";
    
    return 0;
}
