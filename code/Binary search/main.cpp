#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

const std::string filePath = "example.txt";

void increasingSequence(std::vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int degree = 7;
    int n = static_cast<int>(std::pow(10, degree));
    std::vector<int> arr(n);

    increasingSequence(arr, n);

    int target = 0;

    auto start = std::chrono::high_resolution_clock::now();
    int result = binarySearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "First element | Result: " << result << ", Time: " << duration << " ns\n";

    target = 5000000;

    start = std::chrono::high_resolution_clock::now();
    result = binarySearch(arr, target);
    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Middle element | Result: " << result << ", Time: " << duration << " ns\n";

    target = 9999999;

    start = std::chrono::high_resolution_clock::now();
    result = binarySearch(arr, target);
    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Last element | Result: " << result << ", Time: " << duration << " ns\n";

    target = -1;
    start = std::chrono::high_resolution_clock::now();
    result = binarySearch(arr, target);
    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Not found | Result: " << result << ", Time: " << duration << " ns\n";

    return 0;
}