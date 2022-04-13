// leetcode - easy

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        unordered_map<char, char>parmap;
        parmap['{'] = '}';
        parmap['['] = ']';
        parmap['('] = ')';
        
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(!st.empty() && s[i] == parmap[st.top()]) st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
};
