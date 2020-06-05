// Random Pick with Weight
// Given an array w of positive integers, where w[i] describes the weight of index i,
// write a function pickIndex which randomly picks an index in proportion to its weight.

class Solution {
private:
    std::vector<int> v;
public:
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for(int i = 1; i < w.size(); ++i) {
            v.push_back(v.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int weight = rand() % v.back();
        return std::upper_bound(v.cbegin(), v.cend(), weight) - v.cbegin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
