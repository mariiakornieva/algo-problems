/*
*   Happy Number
* 
*
*/

#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> numbers;
        int sum = 0;

        while(n >= 0) {
            sum += std::pow(n % 10, 2);
            n /= 10;
            
            if (n == 0) {
                if (sum == 1) return true;
        
                if (numbers.find(sum) != std::end(numbers)) {
                    return false;
                } else {
                    numbers.insert(sum);
                }
                n = sum;
                sum = 0;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    solution.isHappy(19);
}