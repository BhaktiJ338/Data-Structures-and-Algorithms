//---------------------------approach 1 -------------------------

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+ nums[j]+nums[k] == 0){
                        vector<int>v = {nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>vec(st.begin(), st.end());
        return vec;
    }
};

//---------------------------approach 2 -------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = (-1)*(nums[i]+nums[j]);
                if(binary_search(nums.begin()+j+1, nums.end(), x)){
                    vector<int>v = {nums[i], nums[j], x};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
            }
        }
        vector<vector<int>>vec(st.begin(), st.end());
        return vec;
    }
};

//---------------------------approach 3 -------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        set<vector<int>>set;
        unordered_map<int, int>mp;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            mp[nums[i]] += 1;
        }
        for(int i=0; i<n; i++){
            mp[nums[i]]--;
            for(int j=i+1; j<n; j++){
                mp[nums[j]]--;
                int x = -1*(nums[i]+nums[j]);
                if(mp.find(x) != mp.end() && mp[x] != 0){
                    vector<int>v = {nums[i], nums[j], -1*(nums[i]+nums[j])};
                    sort(v.begin(), v.end());
                    set.insert(v);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>>ans(set.begin(), set.end());
        return ans;
    }
};

//---------------------------approach 4 -------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
                int front = i+1, back = n-1;
                int sum = 0-nums[i];
                while(front < back){
                    if(sum == nums[front]+nums[back]){
                        vector<int>v = {nums[i],nums[front],nums[back]};
                        ans.push_back(v);
                        //skipping duplicates of front
                        while(front < back && nums[front] == nums[front+1]) front++;
                        //skipping duplicates of back
                        while(front < back && nums[back] == nums[back-1]) back--;
                        front++; back--;
                    }
                    else if(nums[front]+nums[back] < sum) front++;
                    else back--;
                }
            //skipping duplicates of i
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
    
};
