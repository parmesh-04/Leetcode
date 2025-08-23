#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentSubset;
        
        // Start the backtracking process from the first element (index 0)
        findSubsets(0, nums, currentSubset, result);
        
        return result;
    }

private:
    void findSubsets(int index, std::vector<int>& nums, std::vector<int>& currentSubset, std::vector<std::vector<int>>& result) {
        // At every step, the current combination is a valid subset. Add it to the result.
        result.push_back(currentSubset);

        // Explore choices by iterating from the current index to the end of the array.
        for (int i = index; i < nums.size(); ++i) {
            // Choice 1: Include the element nums[i]
            currentSubset.push_back(nums[i]);

            // Recurse to explore further with this choice.
            findSubsets(i + 1, nums, currentSubset, result);

            // Choice 2: Backtrack - Do not include nums[i] for the next iteration of the loop.
            // We undo our choice by removing the element.
            currentSubset.pop_back();
        }
    }
};