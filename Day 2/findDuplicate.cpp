//approach 1

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    if(arr.size() == 1) return arr[0];
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1])
            return arr[i];
    }
}


//approach 2

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int slow = arr[0];
    int fast = arr[0];
    
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    
    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
