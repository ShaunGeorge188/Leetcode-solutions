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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftDepth = 0, rightDepth = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        
        // Calculate depth of the extreme left path
        while (l != nullptr) {
            leftDepth++;
            l = l->left;
        }
        
        // Calculate depth of the extreme right path
        while (r != nullptr) {
            rightDepth++;
            r = r->right;
        }
        
        // If they match, it's a full perfect tree. 
        // 1 << leftDepth is equivalent to 2^leftDepth
        if (leftDepth == rightDepth) {
            return (1 << leftDepth) - 1; 
        }
        
        // If not perfect, calculate recursively
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};