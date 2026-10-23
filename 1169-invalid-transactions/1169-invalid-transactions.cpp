class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name(n), city(n);
        vector<int> time(n), amount(n);

        for (int i = 0; i < n; i++) {
            stringstream ss(transactions[i]);
            string t, a;
            getline(ss, name[i], ',');
            getline(ss, t, ',');
            getline(ss, a, ',');
            getline(ss, city[i], ',');
            time[i] = stoi(t);
            amount[i] = stoi(a);
        }

        vector<string> res;
        for (int i = 0; i < n; i++) {
            bool invalid = amount[i] > 1000;
            for (int j = 0; j < n && !invalid; j++) {
                if (i != j && name[i] == name[j] && city[i] != city[j]
                    && abs(time[i] - time[j]) <= 60) {
                    invalid = true;
                }
            }
            if (invalid) res.push_back(transactions[i]);
        }
        return res;
    }
};