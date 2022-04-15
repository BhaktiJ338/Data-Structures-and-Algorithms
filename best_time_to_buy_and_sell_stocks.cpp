// leetcode - easy

//kadene's algo approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX, maxpro = 0;
        for(int i=0; i<prices.size(); i++){
            minp = min(minp, prices[i]);
            maxpro = max(maxpro, prices[i] - minp);
        }
        return maxpro;
    }
};
