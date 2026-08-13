#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Segment Tree Node
struct Node {
    int maxLen;   // Longest repeating character substring in this segment
    int prefLen;  // Length of the longest repeating prefix
    int suffLen;  // Length of the longest repeating suffix
    char prefChar;// The character of the prefix
    char suffChar;// The character of the suffix
    int size;     // Total length of this segment
};

class Solution {
    vector<Node> tree;

    // Merge two child nodes to form a parent node
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;
        
        // Calculate prefix length
        res.prefLen = left.prefLen;
        if (left.prefLen == left.size && left.prefChar == right.prefChar) {
            res.prefLen += right.prefLen;
        }
        
        // Calculate suffix length
        res.suffLen = right.suffLen;
        if (right.suffLen == right.size && right.suffChar == left.suffChar) {
            res.suffLen += left.suffLen;
        }
        
        // Calculate the maximum length in the current segment
        res.maxLen = max(left.maxLen, right.maxLen);
        if (left.suffChar == right.prefChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);
        }
        
        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        // Base case: leaf node
        if (start == end) {
            tree[node] = {1, 1, 1, c, c, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        // Update parent after children are updated
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        
        int k = queryCharacters.length();
        vector<int> ans(k);
        
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            // The root node contains the maximum length for the entire string
            ans[i] = tree[1].maxLen;
        }
        
        return ans;
    }
};