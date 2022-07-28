//--------------------------------approach 1 (TLE)--------------------------
class Solution {
public:
    void solve(int ind, string &s, vector<string>&ans){
        if(ind == s.size()){
            ans.push_back(s);
            return;
        }
        
        for(int i=ind; i<s.size(); i++){
            swap(s[i], s[ind]);
            solve(ind+1, s, ans);
            swap(s[i], s[ind]);        
        }
    }
    
    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1; i<=n; i++){
            s.push_back(i+'0');
        }
        vector<string>ans;
        solve(0, s, ans);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};

//------------------------------------approach 2 -----------------------------

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact = 1;
        for(int i=1; i<n; i++){
            //taking factorial till (n-1)th index 
            //because we are trying to decrese fact by 1
            fact = fact*i;  
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k-1; //to maintain 0-based indexing
        string ans = "";
        
        while(true){
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k / fact);
            
            if(nums.size() == 0) break;
            
            k = k%fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};
