class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        // Step 1: count letters
        vector<long long> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        // Step 2: find center char (odd count), halve the rest
        int center = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) center = i;
            cnt[i] /= 2;
        }

        int halfLen = 0;
        for (int i = 0; i < 26; i++) halfLen += cnt[i];

        const long long CAP = 2000000; // safely bigger than max possible k (1e6)

        // How many distinct arrangements exist for a given multiset? (capped)
        auto countArrangements = [&](vector<long long>& c) -> long long {
            long long result = 1, placed = 0;
            for (int i = 0; i < 26; i++) {
                for (long long j = 1; j <= c[i]; j++) {
                    placed++;
                    result = result * placed / j;   // always divides evenly, stays integer
                    if (result > CAP) return CAP;    // no point computing further
                }
            }
            return result;
        };

        // Step 3: not enough arrangements? bail out
        if (countArrangements(cnt) < k) return "";

        // Step 4: unranking loop — this is exactly what you did by hand
        string half = "";
        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                cnt[i]--;                          // tentatively place letter i
                long long block = countArrangements(cnt);
                if (k <= block) {
                    half += (char)('a' + i);       // commit, k stays the same
                    break;
                } else {
                    k -= block;                    // skip this whole block
                    cnt[i]++;                       // undo, try next letter
                }
            }
        }

        // Step 5: mirror it around the center
        string result = half;
        if (center != -1) result += (char)('a' + center);
        for (int i = (int)half.size() - 1; i >= 0; i--) result += half[i];
        return result;
    }
};