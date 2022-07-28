
//-----------------------------------Approach 1 (using extra space)---------------------------------------

class Solution {
public:
    
    void solve(vector<int>&ds, vector<vector<int>>&ans, int map[], vector<int>arr, int n){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(map[i] == 0){    //ith element not taken yet
                ds.push_back(arr[i]);
                map[i] = 1;
                solve(ds, ans, map, arr, n);
                map[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        int n = nums.size();
        int map[n];
        for(int i=0; i<n; i++) 
            map[i] = 0;
        solve(ds, ans, map, nums, n);
        return ans;
    }
};

//-------------------------------approach 2 (without using extra space)-----------------------------------
class Solution {
public:
    
    void solve(int ind, vector<int>&nums, vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(nums);
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]); //swap
            solve(ind+1, nums, ans);
            swap(nums[i], nums[ind]); //re-swap to maintain previous state of array
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0, nums, ans);
        return ans;
    }
};
