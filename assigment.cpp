#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the pairs whose sum equals the target value
std::vector<std::vector<int>> findPairs(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result.push_back({nums[left], nums[right]});
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}

// Function to merge the array into a single array in ascending order
std::vector<int> mergeArray(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums;
}

// Function to find the combinations whose sum equals the double of the target value
std::vector<std::vector<int>> findCombinations(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        int remaining = target - current;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == remaining) {
                std::vector<int> combination = {current, nums[left], nums[right]};
                result.push_back(combination);
                left++;
                right--;
            } else if (sum < remaining) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 2, -4, -6, -2, 8};
    int target = 4;

    std::cout << "First Combination for \"" << target << "\":\n";
    std::vector<std::vector<int>> pairs = findPairs(nums, target);
    for (const auto& pair : pairs) {
        std::cout << "[" << pair[0] << "," << pair[1] << "], ";
    }
    std::cout << "\n\n";

    std::cout << "Merge Into a Single Array:\n";
    std::vector<int> mergedArray = mergeArray(nums);
    for (const auto& num : mergedArray) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    int doubleTarget = 2 * target;
    std::cout << "Second Combination for \"" << doubleTarget << "\":\n";
    std::vector<std::vector<int>> combinations = findCombinations(nums, doubleTarget);
    for (const auto& combination : combinations) {
        std::cout << "[";
        for (const auto& num : combination) {
            std::cout << num << ",";
        }
        std::cout << "], ";
    }
    std::cout << "\n";

    return 0;
}