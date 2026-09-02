class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            // 1. Dive as far left as possible, pushing nodes onto the stack
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // 2. Pop the leftmost (smallest available) node
            curr = st.top();
            st.pop();
            
            // 3. Decrement k; when k hits 0, this is our target value
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            // 4. Step into the right subtree
            curr = curr->right;
        }
        
        return -1; // Guaranteed not to be reached given valid constraints
    }
};