/*
*   Counting Elements
*
* Given an integer array arr, count element x such that x + 1 is also in arr.
* If there're duplicates in arr, count them seperately.
*/


class Solution {
public:
    int countElements(std::vector<int>& arr) {
        const auto hashSet = std::unordered_multiset<int>(arr.cbegin(), arr.cend());
        return std::count_if(arr.cbegin(), arr.cend(), [&](int elem) {
            return hashSet.find(elem + 1) != std::end(hashSet);
        });
    }
};