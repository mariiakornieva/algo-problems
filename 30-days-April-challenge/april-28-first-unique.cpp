//   You have a queue of integers, you need to retrieve the first unique integer in the queue.
// Implement the FirstUnique class:
// FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
// int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
// void add(int value) insert value to the queue.


class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (auto n : nums) {
            hash[n] += 1;
            unique.push(n);
        }
    }
    
    int showFirstUnique() {
        while (!hash.empty() && hash[unique.front()] > 1) {
            unique.pop();
        }
        if (unique.empty()) return -1;
        return unique.front();
    }
    
    void add(int value) {
        hash[value] += 1;
        if (hash[value] == 1) {
            unique.push(value);
        }
    }
private:    
    std::queue<int> unique;
    std::unordered_map<int,int> hash;
};
