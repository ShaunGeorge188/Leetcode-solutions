#include <bits/stdc++.h>
using namespace std;

struct Req {
    long long e2=0, e3=0, e5=0, e7=0;
    bool isZero() const { return e2==0 && e3==0 && e5==0 && e7==0; }
};

Req digitReq(int d) {
    switch (d) {
        case 2: return {1,0,0,0};
        case 3: return {0,1,0,0};
        case 4: return {2,0,0,0};
        case 5: return {0,0,1,0};
        case 6: return {1,1,0,0};
        case 7: return {0,0,0,1};
        case 8: return {3,0,0,0};
        case 9: return {0,2,0,0};
        default: return {0,0,0,0}; // digit 1
    }
}

Req addReq(const Req& a, const Req& b) {
    return {a.e2+b.e2, a.e3+b.e3, a.e5+b.e5, a.e7+b.e7};
}

Req subClamp(const Req& need, const Req& have) {
    auto c = [](long long x, long long y){ return max(0LL, x - y); };
    return {c(need.e2,have.e2), c(need.e3,have.e3), c(need.e5,have.e5), c(need.e7,have.e7)};
}

// Minimum-count zero-free digit multiset (digits 2-9) covering at least Req r.
array<long long,10> minimalDigitCounts(Req r) {
    array<long long,10> cnt{};
    long long e2=r.e2, e3=r.e3;
    cnt[9] = e3/2; e3 %= 2;
    cnt[8] = e2/3; e2 %= 3;
    long long m = min(e2, e3);
    cnt[6] = m; e2 -= m; e3 -= m;
    cnt[4] = e2/2; e2 %= 2;
    cnt[2] = e2;
    cnt[3] = e3;
    cnt[5] = r.e5;
    cnt[7] = r.e7;
    return cnt;
}

long long totalLen(const array<long long,10>& cnt) {
    long long s=0; for (int d=2; d<=9; d++) s += cnt[d]; return s;
}

string buildFromCounts(const array<long long,10>& cnt, long long padOnes=0) {
    string s;
    s.append(padOnes, '1');
    for (int d=2; d<=9; d++) s.append(cnt[d], char('0'+d));
    return s;
}

class Solution {
public:
    string smallestNumber(string num, long long t) {
        Req REQ;
        long long tt = t;
        while (tt % 2 == 0) { REQ.e2++; tt /= 2; }
        while (tt % 3 == 0) { REQ.e3++; tt /= 3; }
        while (tt % 5 == 0) { REQ.e5++; tt /= 5; }
        while (tt % 7 == 0) { REQ.e7++; tt /= 7; }
        if (tt != 1) return "-1"; // t has a prime factor > 7: impossible at any length

        int L = num.size();
        auto minCnt = minimalDigitCounts(REQ);
        long long Lmin = totalLen(minCnt);

        if (Lmin > L) return buildFromCounts(minCnt);

        vector<Req> P(L+1);
        vector<int> d(L);
        for (int i = 0; i < L; i++) {
            d[i] = num[i] - '0';
            P[i+1] = addReq(P[i], digitReq(d[i]));
        }
        int firstZero = L;
        for (int i = 0; i < L; i++) if (d[i] == 0) { firstZero = i; break; }

        // num itself
        if (firstZero == L) {
            Req rem = subClamp(REQ, P[L]);
            if (rem.isZero()) return num;
        }

        // bump each position from the right; prefix before i must stay zero-free
        for (int i = L-1; i >= 0; i--) {
            if (i > firstZero) continue;
            for (int bigger = d[i]+1; bigger <= 9; bigger++) {
                Req rem = subClamp(REQ, addReq(P[i], digitReq(bigger)));
                auto suffCnt = minimalDigitCounts(rem);
                long long need = totalLen(suffCnt);
                long long space = L - 1 - i;
                if (need <= space) {
                    string res = num.substr(0, i);
                    res += char('0' + bigger);
                    res += buildFromCounts(suffCnt, space - need);
                    return res;
                }
            }
        }

        // no answer at length L -> smallest zero-free number of length L+1
        long long pad = (L + 1) - Lmin;
        return buildFromCounts(minCnt, pad);
    }
};