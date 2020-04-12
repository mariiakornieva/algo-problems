/*
*   Last Stone Weight
*/

class Solution {
private:
    int getMax(std::multiset<int>& stones) {
        int max = *std::prev(stones.cend());
        stones.erase(std::prev(stones.cend()));    
        return max;
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        std::multiset<int> stonesSet(stones.begin(), stones.end());
        
        while (stonesSet.size() > 1) {
            int max = getMax(stonesSet);
            int prev = getMax(stonesSet);

            if (max != prev) {
                stonesSet.insert(max-prev);
            }
        }

        return stonesSet.empty() ? 0 : *stonesSet.begin();
    }
};
