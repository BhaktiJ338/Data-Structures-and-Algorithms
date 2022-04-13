// leetcode - easy

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n!=0)
            nums1.erase(nums1.begin()+m, nums1.begin()+m+n);
        for(auto it:nums2){
            nums1.push_back(it);
        }
        sort(nums1.begin(), nums1.end());
    }
};
