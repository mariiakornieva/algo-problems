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

class SolutionLinearSpace {
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


// Solution in O(1) space using the Floyd's Cycle Detection Algorithm
class SolutionConstantSpace {
public:
    int sumSquaredDigits(int n) {
        int sum = 0;
        while (n) {
            sum += std::pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sumSquaredDigits(slow);
            fast = sumSquaredDigits(sumSquaredDigits(fast));
            if (fast == 1) return true;
        } while (slow != fast);
        return false;
    }
};

int main()
{
    Solution solution;
    solution.isHappy(19);
}