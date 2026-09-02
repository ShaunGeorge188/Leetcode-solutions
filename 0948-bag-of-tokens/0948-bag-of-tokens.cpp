class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // 1. Sort the tokens so we can easily pick the smallest and largest values
        sort(tokens.begin(), tokens.end());
        
        int left = 0;                  // Points to the smallest token
        int right = tokens.size() - 1; // Points to the largest token
        int currentScore = 0;
        int maxScore = 0;
        
        while (left <= right) {
            // Option 1: If we have enough power, play face-up using the smallest token
            if (power >= tokens[left]) {
                power -= tokens[left];
                currentScore++;
                left++;
                maxScore = max(maxScore, currentScore); // Track the peak score achieved
            }
            // Option 2: If we don't have enough power, but we have score to trade 
            // and more than one token left, play face-down using the largest token
            else if (currentScore > 0 && left < right) {
                power += tokens[right];
                currentScore--;
                right--;
            }
            // Option 3: We can't play face-up and can't/shouldn't play face-down, so stop
            else {
                break;
            }
        }
        
        return maxScore;
    }
};