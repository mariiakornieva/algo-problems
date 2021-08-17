/* Permutation Sequence
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/

class Solution {
private:
    std::vector<int> fact = {1};
    std::vector<int> digits;
    
    void solve(std::string& result, int n, int k) {
        if (n == 1) {
            result += std::to_string(digits.back());
            return;
        }
        
        int index = k/fact[n-1];
        if (k % fact[n-1] == 0) {
            index--;
        }
        
        result += std::to_string(digits[index]);
        digits.erase(digits.begin() + index);
        
        solve(result, n-1, k-fact[n-1]*index);
    }
public:
    string getPermutation(int n, int k) {
        fact.resize(n);
        std::generate(fact.begin()+1, fact.end(), [f=1, i=0]() mutable {
            f *= ++i;
            return f;
        });
        digits.resize(n);
        std::iota(digits.begin(), digits.end(), 1);
        
        std::string result{};
        solve(result, n, k);
        return result;
    }
};
