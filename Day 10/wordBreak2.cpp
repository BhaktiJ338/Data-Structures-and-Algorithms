class Solution {
public:

    bool isValid(string &s, vector<string> &dict){
        for(string ss : dict){
            if(ss == s) return true;
        }
        return false;
    }

    void solve(string &s, int start, vector<string> &dict, vector<string> &ans, string &curr) {
        if(start >= s.size()) {
            curr.pop_back(); //remove trailing space
            ans.push_back(curr);
            return;
        }

        for(int end=start; end<s.size(); end++) {
            string temp = s.substr(start, end-start+1);
            if(isValid(temp, dict)){ //check if this word present in dictionary
                string x = curr;    //store curr word to backtrack
                curr += temp + " ";
                solve(s, end+1, dict, ans, curr);
                curr = x;    //backtrack
            }
        }
    }


    vector<string> wordBreak(string s, vector<string>&dict) {
        vector<string> ans;
        string curr;
        solve(s, 0, dict, ans, curr);
        return ans;
    }
};
