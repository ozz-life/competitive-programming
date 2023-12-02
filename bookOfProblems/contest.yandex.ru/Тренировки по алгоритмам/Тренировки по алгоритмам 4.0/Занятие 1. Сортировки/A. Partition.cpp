#include <iostream>
#include <vector>

int partition(std::vector<int>& nums, int pivot) {
    int equal = 0;
    int great = 0;
    for (int i = 0; i < nums.size(); i++) {
        int temp = nums[i];
        if (nums[i] < pivot) {
            std::swap(nums[i], nums[great]);
            std::swap(nums[great], nums[equal]);
            equal++;
            great++;
        } else if (nums[i] == pivot) {
            std::swap(nums[i], nums[great]);
            great++;
        }
    }
    return equal;
}

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "0\n0" << std::endl;
        return 0;
    }

    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int pivot;
    std::cin >> pivot;

    int less = partition(nums, pivot);

    std::cout << less << "\n" << (n - less) << std::endl;

    return 0;
}
