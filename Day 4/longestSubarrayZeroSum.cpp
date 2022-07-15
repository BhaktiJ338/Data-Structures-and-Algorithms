//approach 1 - TLE

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int maxlen = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum = 0;
                for(int k=i; k<=j; k++){
                    sum += arr[k];
                }
                if(sum == 0) maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};

//approach 2

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<int, int>mp;
        int maxlen = 0, sum = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0) maxlen = i+1;
            else{
                if(mp.find(sum) == mp.end()) mp[sum] = i;
                else maxlen = max(maxlen, i-mp[sum]);
            }
        }
        return maxlen;
    }
};
