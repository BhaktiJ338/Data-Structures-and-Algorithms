//approach 1
//using three for loops

//approach 2
//using two for loops

//approach 3 - Kadene's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN, currsum=0;
        for(int i=0; i<nums.size(); i++){
            
            currsum = currsum + nums[i];
            maxsum = max(maxsum, currsum);
            if(currsum < 0)
                currsum = 0;
        }
        return maxsum;
    }
};
