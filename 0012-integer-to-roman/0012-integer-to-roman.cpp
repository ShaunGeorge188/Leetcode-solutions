#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Map values to symbols in strictly descending order
        const std::pair<int, std::string> roman[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        std::string result = "";
        
        // Greedily append the largest possible symbol
        for (const auto& [value, symbol] : roman) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};