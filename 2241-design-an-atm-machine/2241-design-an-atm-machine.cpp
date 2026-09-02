class ATM {
private:
    vector<long long> counts; // Stores the count of $20, $50, $100, $200, $500 notes
    vector<int> values;       // Denominations mapping

public:
    ATM() {
        counts.assign(5, 0);
        values = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            counts[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<long long> toUse(5, 0);
        long long rem = amount;
        
        // Greedily take as many large bills as possible
        for (int i = 4; i >= 0; --i) {
            if (rem == 0) break;
            
            long long countNeeded = rem / values[i];
            long long take = min(countNeeded, counts[i]);
            
            toUse[i] = take;
            rem -= take * values[i];
        }
        
        // If we couldn't fulfill the exact amount, reject the transaction
        if (rem > 0) {
            return {-1};
        }
        
        // Successful withdrawal: deduct from inventory and return result
        vector<int> result(5);
        for (int i = 0; i < 5; ++i) {
            counts[i] -= toUse[i];
            result[i] = static_cast<int>(toUse[i]);
        }
        
        return result;
    }
};