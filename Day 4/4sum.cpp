class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.empty()) return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            //int target3 = target-nums[i];
            for(int j=i+1; j<n; j++){
                long long int target2 = (long long int)target-nums[i]-nums[j];
                int front = j+1;
                int back = n-1;
                
                while(front < back){
                    int twosum = nums[front] + nums[back];
                    if(twosum == target2){
                        vector<int>quad = {nums[i], nums[j], nums[front], nums[back]};
                        ans.push_back(quad);
                        
                        //jumping over duplivates of nums[front]
                        while(front < back && nums[front] == quad[2]) ++front;
                        //jumping over duplivates of nums[back]
                        while(front < back && nums[back] == quad[3]) --back;
                    }
                    else if(twosum < target2) front++;
                    else back--;
                    
                }
                //jump over duplicates of nums[j] , keep j at last duplicate
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            //jump over duplicates of nums[i] , keep i at last duplicate
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};
