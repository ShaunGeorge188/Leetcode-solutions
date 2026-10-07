#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Helper function to check if a string of parentheses is valid
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return result;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true; // Minimum removals reached for this level
            }

            // If we found valid string(s) at this level, don't generate next level
            if (found) continue;

            // Generate next state by removing 1 parenthesis at a time
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') continue;

                string nextState = current.substr(0, i) + current.substr(i + 1);

                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
        }

        return result;
    }
};