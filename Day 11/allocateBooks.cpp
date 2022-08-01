
bool isPossible(int barrier, vector<int>arr, int k){
    int allocated_stud = 1, pages = 0;
    for(int i=0; i<arr.size(); i++){
        //individual book has pages > barrier
        if(arr[i] > barrier) 
            return false;
        //curr student can not take any more pages
        else if(arr[i] + pages > barrier){
            allocated_stud += 1;
            pages = arr[i];
        }
        else{
            pages += arr[i];
        }
    }
    if(allocated_stud > k) return false;
    else return true;
}

int Solution::books(vector<int> &arr, int k) {
    if(k > arr.size()) return -1;
    int sumPages = 0, minpages = 0;
    
    int low = arr[0];
    int high = 0;
    
    for(int i=0; i<arr.size(); i++){
        low = min(low, arr[i]);
        high += arr[i];
    }
    
    while(low <= high){
        int mid = (low+high)/2;
        
        if(isPossible(mid, arr, k)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
