//------------------approach 1 ---------------------------

int removeDuplicates(vector<int> &arr, int n) {
	  set < int > set;
      for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
      }
      return set.size();
}

//------------------approach 2 ---------------------------

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
