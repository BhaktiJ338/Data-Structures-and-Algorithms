//approach 1

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
		
        unordered_set<char>set;
        int maxlen = 0, i=0;
        
        for(int j=0; j<str.length(); j++){
            if(set.find(str[j]) != set.end()){ 
                while(i<j && set.find(str[j]) != set.end()){
                    set.erase(str[i]);
                    i++;
                }
            }
            set.insert(str[j]);
            maxlen = max(maxlen, j-i+1);
        }
        return maxlen;
    }
};


//approach 2

int uniqueSubstrings(string s)
{
    vector<int>mp(256, -1);
    int left = 0, right = 0, len = 0;
    while(right < s.length()){
        if(mp[s[right]] != -1) left = max(left, mp[s[right]]+1);
        mp[s[right]] = right;
        len = max(len , right-left+1);
        right++;
    }
    return len;
}
