class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        
      set < int > hash;
      for (int num: nums)  hash.insert(num);

      int maxlen = 0;

      for (int num: hash) {
            if (!hash.count(num - 1)) {
                  int currnum = num;
                  int currlen = 1;

                  while (hash.count(currnum + 1)) {
                    currnum += 1;
                    currlen += 1;
                  }
                  maxlen = max(maxlen, currlen);
            }
      }
      return maxlen;
    }
};
