int findMinimumCoins(int amount) 
{
    int coins = 0;
    vector<int>arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int i=arr.size()-1;
    
    while(amount > 0){
        if(amount >= arr[i]){
            amount = amount - arr[i];
            coins++;
        }
        else {
            i--;
        }
    }
    return coins;
}
