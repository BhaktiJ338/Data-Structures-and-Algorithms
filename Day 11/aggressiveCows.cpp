//function to determine whether placing c cows is possible by keeping minimum distance 'd'.
bool isPossible(vector<int>arr, int n , int c ,int d){
    int lastcowpos = arr[0];    //position where last cow was placed
    int totalcows = 1;          //total cows placed
    
    for(int i=1; i<n; i++){
        if(arr[i]-lastcowpos >= d){
            totalcows++;
            lastcowpos = arr[i];
        }
        if(totalcows >= c) return true;
    }
    
    return false;   //can't place C cows keeping this min dist 
} 

int aggressiveCows(vector<int> &arr, int c)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1;//min distance
    int high = arr[n-1]-arr[0]; //max distance

    while(low <= high){

        int mid = (low+high)/2;

        if(isPossible(arr, n, c, mid))
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return high;
}
