#include <iostream>
#include <vector>

bool isPresent(const std::vector<int>& arr, int k) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            return true;
        }
        if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 6};
    int k1 = 6;
    std::cout << std::boolalpha << isPresent(arr1, k1) << std::endl; // Output: true

    std::vector<int> arr2 = {1, 2, 4, 5, 6};
    int k2 = 3;
    std::cout << std::boolalpha << isPresent(arr2, k2) << std::endl; // Output: false

    std::vector<int> arr3 = {2, 3, 5, 6};
    int k3 = 1;
    std::cout << std::boolalpha << isPresent(arr3, k3) << std::endl; // Output: false

    return 0;
}
