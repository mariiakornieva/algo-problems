/*
*   Last Stone Weight
*/

class SolutionWithMultiSet {
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

class SolutionWithPQueue {
private:
    int getMax(std::priority_queue<int>& stones) {
        int max = stones.top();
        stones.pop();  
        return max;
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> stonesQueue(stones.begin(), stones.end());
        
        while (stonesQueue.size() > 1) {
            int max = getMax(stonesQueue);
            int prev = getMax(stonesQueue);

            if (max != prev) {
                stonesQueue.push(max-prev);
            }
        }

        return stonesQueue.empty() ? 0 : stonesQueue.top();
    }
};
