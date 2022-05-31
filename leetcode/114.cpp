// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


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
    
    
    void helper(TreeNode* root, vector<TreeNode*>& arr){
            if(root == NULL){
                return; 
            }
            arr.push_back(root); 
            helper(root->left, arr); 
            helper(root->right, arr); 
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> arr; 
        helper(root, arr); 
        TreeNode* tmp_root = NULL; 
        for(int i = arr.size() - 1; i >= 0; i--){
            TreeNode* tmp = arr[i]; 
            tmp->left = NULL; 
            tmp->right = tmp_root; 
            tmp_root = tmp; 
        }
        root = tmp_root; 
    }
};