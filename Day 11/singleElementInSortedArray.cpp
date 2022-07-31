int uniqueElement(vector<int> arr, int n)
{
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid%2 == 0){
            if(arr[mid] == arr[mid-1]){
                high = mid-2;
            }
            else if(arr[mid] == arr[mid+1]){
                low = mid+2;
            }
            else return arr[mid];
        }
        else{
            if(arr[mid] == arr[mid-1]){
                low = mid+1;
            }
            else if(arr[mid] == arr[mid+1]){
                high = mid-1;
            }
            else return arr[mid];
        }
    }
    return arr[low];
}


//we can avoid writing multiple conditional statements using xor property

//even index -> 1st element in pair
//odd index -> 2nd element in pair

//if mid is even mid^1 will be odd i.e. mid+1 == mid^1
//if mid is odd mid^1 will be even i.e. mid-1 == mid^1

int uniqueElement(vector<int> arr, int n)
{
    int low = 0, high = arr.size()-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == arr[mid^1]){ 
            low = mid+1;    //target is in right half
        }
        else{
            high = mid-1;    //target is in left half
        }
    }
    return arr[low];
}

