/*
*   Backspace String Compare
*
* Given two strings S and T, return if they are equal
* when both are typed into empty text editors. # means
* a backspace character.
*/

#include <stack>
#include <string>

// Solution O(n+m) space using stack
class Solution {
private:
    std::stack<char> backStr(std::string S) {
        std::stack<char> st;
        for (auto c : S) {
            if (c == '#') {
                if (!st.empty()) st.pop();
            } else {
                st.push(c);
            }
        }
        return st;
    }

public:
    bool backspaceCompare(std::string S, std::string T) {
        return backStr(S) == backStr(T);
    }
};


class SolutionOptimized {
public:
    bool backspaceCompare(std::string S, std::string T) {
        int s1 = S.length() - 1;
        int s2 = T.length() - 1;
        int countS = 0, countT = 0;

        while (s1 >= 0 || s2 >= 0) {
            while (s1 >= 0) {
                if (S[s1] == '#') { countS++; s1--; }
                else if (countS > 0) { countS--; s1--; }
                else break;
            }
            
            while (s2 >= 0) {
                if (T[s2] == '#') { countT++; s2--; }
                else if (countT > 0) { countT--; s2--; }
                else break;
            }
            
            if ((s1 >= 0 && s2 >= 0 && S[s1] != T[s2]) ||
                (s1 >= 0 != s2 >= 0)) {
                return false;
            }

            --s1; --s2;
        }
        
        return true;
    }

};