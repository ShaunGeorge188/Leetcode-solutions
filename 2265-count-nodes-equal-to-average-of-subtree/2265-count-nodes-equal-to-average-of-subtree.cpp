#include <utility>

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
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    // Returns a pair: {sum_of_values, number_of_nodes}
    std::pair<int, int> dfs(TreeNode* node, int& result) {
        // Base case: an empty node has sum 0 and count 0
        if (node == nullptr) {
            return {0, 0};
        }

        // 1. Process left and right subtrees
        std::pair<int, int> left = dfs(node->left, result);
        std::pair<int, int> right = dfs(node->right, result);

        // 2. Calculate values for the current subtree
        int current_sum = left.first + right.first + node->val;
        int current_count = left.second + right.second + 1;

        // 3. Check if the current node matches the average criteria
        // (Integer division naturally truncates toward zero as required)
        if (current_sum / current_count == node->val) {
            result++;
        }

        // 4. Pass the calculated sum and count up to the parent
        return {current_sum, current_count};
    }
};