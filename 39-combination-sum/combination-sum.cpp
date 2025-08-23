#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        
        // Sorting is an optional optimization to prune the search space earlier.
        std::sort(candidates.begin(), candidates.end());
        
        // Start the backtracking process from the first element (index 0).
        findCombinations(0, target, candidates, currentCombination, result);
        
        return result;
    }

private:
    void findCombinations(int index, int target, std::vector<int>& candidates, 
                          std::vector<int>& currentCombination, std::vector<std::vector<int>>& result) {
        
        // Base Case 1: We've found a valid combination.
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        // Explore choices by iterating from the current index onwards.
        for (int i = index; i < candidates.size(); ++i) {
            // Optimization: If the current candidate is larger than the remaining target,
            // no further candidates in the sorted array will work.
            if (candidates[i] > target) {
                break;
            }

            // Choose: Add the current candidate to our combination.
            currentCombination.push_back(candidates[i]);

            // Recurse: Continue searching from the current index 'i' (allowing reuse).
            findCombinations(i, target - candidates[i], candidates, currentCombination, result);
            
            // Backtrack: Remove the candidate to explore other paths.
            currentCombination.pop_back();
        }
    }
};