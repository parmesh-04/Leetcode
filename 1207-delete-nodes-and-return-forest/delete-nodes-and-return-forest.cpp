/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(TreeNode* node, unordered_set<int>& st,vector<TreeNode*>& ans){
        if(node==nullptr) return nullptr;
        node->left=solve(node->left,st,ans);
        node->right=solve(node->right,st,ans);
        if(st.count(node->val)){
            if(node->left) ans.push_back(node->left);
            if(node->right) ans.push_back(node->right);
            return nullptr;
        }
        return node;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        
        if(!st.count(root->val)){
            ans.push_back(root);
        }
      
        root=solve(root,st,ans);
        return ans;

    }
};