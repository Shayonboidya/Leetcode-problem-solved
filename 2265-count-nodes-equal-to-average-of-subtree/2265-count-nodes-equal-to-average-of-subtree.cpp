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
    int res;
    pair<int, int> solved(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        auto p1 = solved(root->left);
        auto p2 = solved(root->right);
        int total_sum = p1.first + p2.first + root->val;
        int total_cnt = p1.second + p2.second + 1;
        if(root-> val == (total_sum / total_cnt)){
            res ++;
        }
        return {total_sum, total_cnt};
        
    }
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        solved(root);
        return res;
    }
};