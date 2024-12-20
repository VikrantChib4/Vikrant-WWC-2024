#include <iostream>
using namespace std;

int rem(int nums[], int n) {
    if (n == 0) return 0;

    int slow = 0; 
    for (int fast = 1; fast < n; ++fast) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1; 
}

int main() {
    int nums[] = {1, 1, 2, 3, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    int uniqueCount = rem(nums, n);

    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Modified array: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
