/*
*   Happy Number
* 
* A happy number is a number defined by the following process:
* Starting with any positive integer, replace the number by
* the sum of the squares of its digits, and repeat the process
* until the number equals 1 (where it will stay), or it loops
* endlessly in a cycle which does not include 1.
* Those numbers for which this process ends in 1 are happy numbers.
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