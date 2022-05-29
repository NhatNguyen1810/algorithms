// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


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
    
    int max_depth(TreeNode* root){
        if(root == NULL){
            return 0; 
        }
        return 1 + max(max_depth(root->left), max_depth(root->right)); 
    }
    void helper(vector<vector<TreeNode*>>& zigzag_tree, int level, TreeNode* root){
        if(root == NULL){
            return; 
        }
        zigzag_tree[level].push_back(root);
        helper(zigzag_tree, level + 1, root->left); 
        helper(zigzag_tree, level + 1, root->right); 
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int depth = max_depth(root); 
        vector<vector<TreeNode*>> zigzag_tree(depth); 
        helper(zigzag_tree, 0, root); 
        vector<vector<int>> zigzag_order(depth); 
        for(int i = 0; i < depth; i++){
            if(i % 2 == 1){
                for(int j = zigzag_tree[i].size() - 1; j >= 0; j--){
                    zigzag_order[i].push_back(zigzag_tree[i][j]->val); 
                }
            }
            else{
                for(int j = 0; j < zigzag_tree[i].size(); j++){
                    zigzag_order[i].push_back(zigzag_tree[i][j]->val); 
                }
            }
        }
        return zigzag_order; 
    }
};