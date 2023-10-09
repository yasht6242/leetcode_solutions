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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average;
        queue<TreeNode*> q;
        int qSize;
        double total;
        q.push(root);
        while(q.size()>0){
            qSize = q.size();
            total=0;
            for(int i=0;i<qSize;i++){
                TreeNode* tree = q.front();
                total=total+tree->val;
                if(tree->left!=NULL){
                    q.push(tree->left);
                }
                if(tree->right!=NULL){
                    q.push(tree->right);
                }
                q.pop();
            }
            total=total/qSize;
            average.push_back(total);
        }
        return average;
    }
};