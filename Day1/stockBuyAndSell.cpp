//approach 1 - TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = INT_MIN;
        for(int i=0; i<prices.size(); i++){
            for(int j=i+1; j<prices.size(); j++){
                int currpro = prices[j] - prices[i] ;
                if(currpro>maxpro){
                    maxpro = currpro;
                }
            }
        }
        if(maxpro>0)
            return maxpro;
        else
            return 0;
    }
};

//approach 2
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit = 0;
    int minP = INT_MAX;
    for(int i=0; i<prices.size(); i++){
        minP = min(prices[i], minP);
        profit = max(profit, prices[i] - minP);
    }
    return profit;
}
