#include <bits/stdc++.h>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int curr_max = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums.at(i) == 1){
                curr_max += 1;
                if(max < curr_max){
                    max = curr_max;
                }
            }else{
                curr_max = 0;
            }
        }
        return max;
    }
};
