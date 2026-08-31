class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int first_critical = -1;
        int last_critical = -1;
        int min_dist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;
            
            // Check if the current node is a local maxima or minima
            if ((curr->val > prev->val && curr->val > next_node->val) || 
                (curr->val < prev->val && curr->val < next_node->val)) {
                
                if (first_critical == -1) {
                    // Record the very first critical point we see
                    first_critical = index;
                } else {
                    // Update the minimum distance using the most recently seen critical point
                    min_dist = min(min_dist, index - last_critical);
                }
                
                // Update the last seen critical point for the next iteration
                last_critical = index;
            }
            
            // Move pointers forward
            prev = curr;
            curr = next_node;
            index++;
        }

        // If min_dist is still INT_MAX, we found fewer than 2 critical points
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }

        // max distance is always the gap between the last and first critical points found
        return {min_dist, last_critical - first_critical};
    }
};