class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int freq[26] = {0};
        for(char c : s) freq[c - 'a']++;

        vector<pair<int, char>> altStack;
        vector<array<int, 26>> snapshots;

        string result(n, ' ');
        int i = 0;
        bool fullyMatched = true;

        for(i = 0; i < n; i++){
            char c = target[i];

            char alt = 0;
            for(int k = c - 'a' + 1; k < 26; k++){
                if(freq[k] > 0) {alt = 'a' + k; break;}
            }

            if(alt) {
                array<int, 26> snap;
                copy(begin(freq), end(freq), snap.begin());
                altStack.push_back({i, alt});
                snapshots.push_back(snap);
            }

            if(freq[c - 'a'] > 0) {
                freq[c - 'a']--;
                result[i] = c;
            } else{
                fullyMatched = false;
                break;
            }
        }
                int divergePos;
        char altChar;
        array<int,26> useFreq;

        if (fullyMatched || i == n) {
            // reached the end matching exactly -> not strictly greater, must backtrack
            if (altStack.empty()) return "";
            divergePos = altStack.back().first;
            altChar = altStack.back().second;
            useFreq = snapshots.back();
        } else {
            // failed at position i; check if THIS position already had an alt
            bool foundHere = false;
            for (auto &p : altStack) {
                if (p.first == i) { foundHere = true; break; }
            }
            if (foundHere) {
                divergePos = i;
                altChar = altStack.back().second; // it was pushed right before failing
                useFreq = snapshots.back();
            } else {
                if (altStack.empty()) return "";
                divergePos = altStack.back().first;
                altChar = altStack.back().second;
                useFreq = snapshots.back();
            }
        }

        useFreq[altChar - 'a']--;
        string ans = target.substr(0, divergePos) + altChar;
        for (int k = 0; k < 26; k++)
            ans += string(useFreq[k], 'a' + k);

        return ans;
    }
};