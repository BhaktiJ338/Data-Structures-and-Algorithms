//Moore's voting algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=-1, cand2=-1, cnt1=0, cnt2=0;
        int n = nums.size();
        for(int i=0; i<n; i++){ 
            
            if(nums[i] == cand1) cnt1++;
            
            else if(nums[i] == cand2) cnt2++;
            
            else if(cnt1 == 0){
                cand1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                cand2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--; cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == cand1) cnt1++;
            else if(nums[i] == cand2) cnt2++;
        }
        vector<int>ans;
        if(cnt1 > floor(n/3)) ans.push_back(cand1);
        if(cnt2 > floor(n/3)) ans.push_back(cand2);
        return ans;
    }
};
