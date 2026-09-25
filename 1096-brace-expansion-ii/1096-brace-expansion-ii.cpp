class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int index = 0;
        set<string> result = parseExpr(expression, index);
        return vector<string>(result.begin(), result.end());
    }

private:
    set<string> parseExpr(const string& expr, int& i) {
        set<string> unionSet;
        set<string> concatSet = {""}; // Identity element for concatenation

        while (i < expr.size() && expr[i] != '}') {
            if (expr[i] == ',') {
                // Union operation: flush current concatenated group into unionSet
                unionSet.insert(concatSet.begin(), concatSet.end());
                concatSet = {""};
                i++;
            } else {
                set<string> nextGroup;
                if (expr[i] == '{') {
                    i++; // Skip '{'
                    nextGroup = parseExpr(expr, i);
                    i++; // Skip '}'
                } else {
                    // Single character word
                    nextGroup = {string(1, expr[i])};
                    i++;
                }

                // Concatenation operation (Cartesian product)
                set<string> temp;
                for (const string& a : concatSet) {
                    for (const string& b : nextGroup) {
                        temp.insert(a + b);
                    }
                }
                concatSet = move(temp);
            }
        }

        // Add the last accumulated concatenation set to the union set
        unionSet.insert(concatSet.begin(), concatSet.end());
        return unionSet;
    }
};