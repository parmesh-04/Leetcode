#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        // Start the backtracking process with an empty string
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string currentString, int openCount, int closeCount, int n) {
        // Base Case: If the string is complete, add it to the result and return.
        if (currentString.length() == n * 2) {
            result.push_back(currentString);
            return;
        }

        // --- Recursive Step ---

        // Choice 1: Add an open parenthesis '(' if we can.
        if (openCount < n) {
            backtrack(result, currentString + "(", openCount + 1, closeCount, n);
        }

        // Choice 2: Add a closing parenthesis ')' if it's valid to do so.
        if (closeCount < openCount) {
            backtrack(result, currentString + ")", openCount, closeCount + 1, n);
        }
    }
};