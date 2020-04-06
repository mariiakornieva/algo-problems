/*
*   Group Anagrams
*
*/

#include <vector>
#include <multiset>
#include <map>

class Solution {
private:
    using vvs = std::vector<std::vector<std::string>>;
    using vs = std::vector<std::string>;
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        vvs anagrams;
        std::map<std::multiset<char>, int> hash;
        int count = 0;
        for (auto const& str : strs) {
            std::multiset<char> set(str.begin(), str.end());
            
            if (hash.find(set) != std::end(hash)) {
                anagrams[hash[set]].push_back(str);
            } else {
                anagrams.push_back(vs{str});
                hash[set] = count++;
            }
        }
        return anagrams;
    }
};