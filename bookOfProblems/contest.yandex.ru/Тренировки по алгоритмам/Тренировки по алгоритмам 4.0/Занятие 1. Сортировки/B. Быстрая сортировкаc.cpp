#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

std::default_random_engine generator;

int partition(std::vector<int>& nums, int left, int right) {
    int pivotIndex = left + std::uniform_int_distribution<int>(0, right - left)(generator);
    int pivot = nums[pivotIndex];
    std::swap(nums[pivotIndex], nums[right]);
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            std::swap(nums[i], nums[j]);
            i++;
        }
    }
    std::swap(nums[i], nums[right]);
    return i;
}

void quickSort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
        int p = partition(nums, left, right);
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }
}

int main() {
    std::ifstream input("input.txt");
    int n;
    input >> n;
    if (n == 0) {
        std::cout << std::endl;
        return 0;
    }
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        input >> nums[i];
    }
    if (!std::is_sorted(nums.begin(), nums.end())) {
        quickSort(nums, 0, nums.size() - 1);
    }
    input.close();

    std::ofstream output("output.txt");
    for (int num : nums) {
        output << num << " ";
    }
    output.close();

    return 0;
}
