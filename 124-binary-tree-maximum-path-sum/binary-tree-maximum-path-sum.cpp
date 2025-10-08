#include <climits>
using namespace std;
class Solution {
public:
    int max_sum = INT_MIN;

    int max_gain(TreeNode* node) {
        if (!node) return 0;

        
        int left_gain = max(max_gain(node->left),0);
        int right_gain = max(max_gain(node->right),0);

     
        max_sum=max(max_sum,node->val+left_gain+right_gain);
       
        return node->val + max(left_gain, right_gain);
    }

    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};