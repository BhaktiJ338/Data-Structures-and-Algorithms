class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void solve(int ind, vector<string>&subans, vector<vector<string>>&ans, string s, int n){
        if(ind == n){
            ans.push_back(subans);
            return;
        }
        
        for(int i=ind; i<n; i++){
            //partitioning if string ind-i th index is palindrome 
            if(isPalindrome(s, ind, i)){
                subans.push_back(s.substr(ind, i-ind+1));
                solve(i+1, subans, ans, s, n);
                subans.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>subans;
        vector<vector<string>>ans;
        int n = s.length();
        solve(0, subans, ans, s, n);
        return ans;
    }
};
