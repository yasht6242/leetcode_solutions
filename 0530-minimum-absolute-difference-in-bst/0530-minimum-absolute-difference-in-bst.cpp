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
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        TreeNode* prev = NULL;
        inOrderTraversal(root,prev, min_diff);
        return min_diff;
    }
    void inOrderTraversal(TreeNode*& node, TreeNode*& prev, int& min_diff){
        if(node==NULL){
            return;
        }
        inOrderTraversal(node->left,prev,min_diff);
        if(prev!=NULL){
            min_diff = min(min_diff, abs(node->val-prev->val));
        }
        prev=node;
        inOrderTraversal(node->right,prev,min_diff);

    }
};