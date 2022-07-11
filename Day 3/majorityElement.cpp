//approach 1 - using hashing

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>mp;
        int n = nums.size(), i;
        for(i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > floor(n/2)) break;
        }
        return nums[i];
    }
};

//approach 2 - Moore's voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, temp = 0;
        for(int i: nums){
            if(count == 0) temp = i;
            if(temp == i){
                count += 1;
            }else
                count -= 1;
        }
        return temp;
    }       
};
