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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        
        vector<vector<int>>ans;
        queue<TreeNode*>levels;
        levels.push(root);
        int levelCnt = 0;
        
        while(!levels.empty()){
            int levelSize = levels.size();
            vector<int>currLevel;
            
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = levels.front();
                currLevel.push_back(curr->val);
                levels.pop();

             
                if(curr->left) levels.push(curr->left);
                if(curr->right) levels.push(curr->right);
            }
            if(levelCnt % 2 == 1 ) {
                reverse(currLevel.begin(),currLevel.end());
                ans.push_back(currLevel);
            }
            else  ans.push_back(currLevel);
             
            levelCnt++;
        }
        return ans;
    }
};