class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
        int need[26] = {0};
        for (char c : l) {
            if (isalpha(static_cast<unsigned char>(c))) {
                need[tolower(c) - 'a']++;
            }
        }

        string best = "";
        for (const string& w : words) {
            if (!best.empty() && w.size() >= best.size()) continue;  // can't beat current best

            int have[26] = {0};
            for (char c : w) have[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (have[i] < need[i]) { ok = false; break; }
            }
            if (ok) best = w;
        }
        return best;
    }
};