// struct Item{
//     int value;
//     int weight;
// };

class Solution
{
    public:
    static bool comp(Item i1, Item i2){
        double vpw1 = (double)i1.value/(double)i1.weight;
        double vpw2 = (double)i2.value/(double)i2.weight;
        return vpw1 > vpw2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        int i=0, currwgt = 0;
        double ans = 0;
        while(i < n){
            if(arr[i].weight+currwgt <= w){
                ans += arr[i].value;
                currwgt += arr[i].weight;
                i++;
            }
            else{
                int remainingWeight = w - currwgt; 
                ans += ((double)arr[i].value/(double)arr[i].weight)*(double)remainingWeight;
                break;
            }
        }
        return ans;
    }
        
};
