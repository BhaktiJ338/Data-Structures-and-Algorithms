int search(int* arr, int n, int target) {
    int low = 0;
    int high = n-1;
    
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        
        else if(arr[low] <= arr[mid]){	//low to mid is sorted
            //target lies in sorted part
            if(target >= arr[low] && target <= arr[mid-1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else {    //mid to high is sorted
            //target lies in sorted part
            if(target >= arr[mid] && target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
