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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }

        int tar=depth-1;
        int h=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto top=q.front();
                q.pop();
                if(h==tar){
                    TreeNode* l=new TreeNode(val);
                    TreeNode* r=new TreeNode(val);
                    l->left=top->left;
                    r->right=top->right;
                    top->left=l;
                    top->right=r;
                }

                if(top->left !=nullptr){
                    q.push(top->left);
                }

                if(top->right!=nullptr){
                    q.push(top->right);
                }
            }
            h++;
            
        }
        return root;
    }
};